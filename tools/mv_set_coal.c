/*******************************************************************************
Copyright (C) Marvell International Ltd. and its affiliates

This software file (the "File") is owned and distributed by Marvell
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the two
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.

********************************************************************************
Marvell Commercial License Option

If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.

********************************************************************************
Marvell GPL License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File in accordance with the terms and conditions of the General
Public License Version 2, June 1991 (the "GPL License"), a copy of which is
available along with the File in the license.txt file or by writing to the Free
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or
on the worldwide web at http://www.gnu.org/licenses/gpl.txt.

THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED
WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY
DISCLAIMED.  The GPL License provides additional details about this warranty
disclaimer.
********************************************************************************
Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    *   Redistributions of source code must retain the above copyright notice,
	    this list of conditions and the following disclaimer.

    *   Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in the
	documentation and/or other materials provided with the distribution.

    *   Neither the name of Marvell nor the names of its contributors may be
	used to endorse or promote products derived from this software without
	specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#include <sys/types.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <paths.h>
#include <stdlib.h>

#include <sys/sysctl.h>
#include <sys/time.h>

#define ETH_SDMA_CONFIG_REG(port)           (MV_ETH_REG_BASE(port) + 0x41c)
#define MV_ETH_REG_BASE(port)      	(((port) == 0) ? 0x72000 : 0x82000)
#define ETH_RX_INTR_COAL_OFFSET             7
#define ETH_RX_INTR_COAL_ALL_MASK           (0x3fff<<ETH_RX_INTR_COAL_OFFSET)
#define ETH_RX_INTR_COAL_MASK(value)        (((value)<<ETH_RX_INTR_COAL_OFFSET)  \
                                             & ETH_RX_INTR_COAL_ALL_MASK)

#define ETH_TX_FIFO_URGENT_THRESH_REG(port) (MV_ETH_REG_BASE(port) + 0x474)
#define ETH_TX_INTR_COAL_OFFSET             4


mv_reg_read(unsigned int reg)
{
    unsigned int value;
    FILE *resource_dump;

    resource_dump = fopen ("/proc/resource_dump" , "w");
    if (!resource_dump) {
      printf ("Eror opening file /proc/resource_dump\n");
      exit(-1);
    }
    fprintf (resource_dump,"register  r %08x",reg);
    fclose (resource_dump);
    resource_dump = fopen ("/proc/resource_dump" , "r");
    if (!resource_dump) {
      printf ("Eror opening file /proc/resource_dump\n");
      exit(-1);
    }
    fscanf (resource_dump , "%x" , &value);
    fclose (resource_dump);

    return value;
}

void
mv_reg_write(unsigned int reg, unsigned int value)
{
    FILE *resource_dump;

    resource_dump = fopen ("/proc/resource_dump" , "w");
    if (!resource_dump) {
      printf ("Eror opening file /proc/resource_dump\n");
      exit(-1);
    }
    fprintf (resource_dump,"register  w %08x %08x",reg,value);
    fclose (resource_dump);
    return;
}

/*******************************************************************************
* mvEthRxCoalSet  - Sets coalescing interrupt mechanism on RX path
*
* DESCRIPTION:
*       This routine sets the RX coalescing interrupt mechanism parameter.
*       This parameter is a timeout counter, that counts in 64 tClk
*       chunks, that when timeout event occurs a maskable interrupt occurs.
*       The parameter is calculated using the tCLK frequency of the
*       MV-64xxx chip, and the required number is in micro seconds.
*
* INPUT:
*       MV_U32          uSec        - Number of micro seconds between
*                                   RX interrupts
*
* RETURN:
*       None.
*
* COMMENT:
*   1 sec           - TCLK_RATE clocks
*   1 uSec          - TCLK_RATE / 1,000,000 clocks
*
*   Register Value for N micro seconds -  ((N * ( (TCLK_RATE / 1,000,000)) / 64)
*
* RETURN:
*       None.
*
*******************************************************************************/
unsigned int    mvEthRxCoalSet (unsigned int uSec)
{
    unsigned int	  port = 0;
    unsigned int 	  Tclk = 166000000;
    unsigned int          coal = ((uSec * ( Tclk / 1000000)) / 64);
    unsigned int          portSdmaCfgReg;

    portSdmaCfgReg =  mv_reg_read(ETH_SDMA_CONFIG_REG(port));
    portSdmaCfgReg &= ~ETH_RX_INTR_COAL_ALL_MASK;
    portSdmaCfgReg |= (ETH_RX_INTR_COAL_MASK(coal));
    mv_reg_write(ETH_SDMA_CONFIG_REG(port), portSdmaCfgReg);
    return coal;
}

/*******************************************************************************
* mvEthTxCoalSet - Sets coalescing interrupt mechanism on TX path
*
* DESCRIPTION:
*       This routine sets the TX coalescing interrupt mechanism parameter.
*       This parameter is a timeout counter, that counts in 64 tClk
*       chunks, that when timeout event occurs a maskable interrupt
*       occurs.
*       The parameter is calculated using the tCLK frequency of the
*       MV-64xxx chip, and the required number is in micro seconds.
*
* INPUT:
*       MV_U32          uSec        - Number of micro seconds between
*                                   RX interrupts
*
* RETURN:
*       None.
*
* COMMENT:
*   1 sec           - TCLK_RATE clocks
*   1 uSec          - TCLK_RATE / 1,000,000 clocks
*
*   Register Value for N micro seconds -  ((N * ( (TCLK_RATE / 1,000,000)) / 64)
*
*******************************************************************************/
unsigned int    mvEthTxCoalSet(unsigned int uSec)
{
    unsigned int          port = 0;
    unsigned int          Tclk = 166000000;
    unsigned int          coal = ((uSec * (Tclk / 1000000)) / 64);

    /* Set TX Coalescing mechanism */
    mv_reg_write (ETH_TX_FIFO_URGENT_THRESH_REG(port),
                  (coal << ETH_TX_INTR_COAL_OFFSET));
    return coal;
}

int
main(int argc, char **argv)
{
        unsigned int direct,usec;

        if (argc == 3) {
                sscanf(argv[1], "%x", &direct);
                sscanf(argv[2], "%x", &usec);
        }else{ printf ("Usage: mv_set_coal <direction 0-Rx 1-Tx> <coal in micro sec>\n");
                return 0;
        }

        if(direct == 0)
		mvEthRxCoalSet(usec);
	else
		mvEthTxCoalSet(usec);

        return 1;
}
