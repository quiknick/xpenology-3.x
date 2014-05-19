/*
Copyright (c) 2008 Silicon Laboratories, Inc.
2008-03-12 17:24:23 */

enum {
    RING_F20_45VRMS_0VDC_LPR,
    RING_F20_45VRMS_0VDC_BAL,
    RING_F20_55VRMS_48VDC_LPR,
    RING_F25_45VRMS_0VDC_LPR,
    RING_F25_45VRMS_0VDC_BAL,
    RING_F25_55VRMS_48VDC_LPR
};

enum {
    DCFEED_48V_20MA,
    DCFEED_48V_25MA
};

enum {
    ZSYN_600_0_0,
    ZSYN_270_750_150,
    ZSYN_370_620_310,
    ZSYN_220_820_120,
    ZSYN_600_0_1000,
    ZSYN_200_680_100,
    ZSYN_220_820_115
};

enum {
	FSK_DEFAULT_CONFIG
};

enum {
	TONEGEN_FCC_DIAL,
	TONEGEN_FCC_BUSY,
	TONEGEN_FCC_RINGBACK,
	TONEGEN_FCC_REORDER,
	TONEGEN_FCC_CONGESTION
};

enum {
	PCM_DEFAULT_CONFIG
};

enum {
   GEN_PARAM_FLYBACK,
   GEN_PARAM_QCUK
};
