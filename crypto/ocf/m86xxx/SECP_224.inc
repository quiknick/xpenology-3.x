
static const EC_CURVE_DATA SEC224R1 = {
	28,
	{0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	//(next power 2)/2=2^223
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01},	// modulus m (p), Prime-modulus:(p-or-m)
	{0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},	// m' ,modular inverse of m (mod R)
	{0xB7,0x0E,0x0C,0xBD,0x6B,0xB4,0xBF,0x7F,0x32,0x13,0x90,0xB9,0x4A,0x03,0xC1,0xD3,0x56,0xC2,0x11,0x22,0x34,0x32,0x80,0xD6,0x11,0x5C,0x1D,0x21},	// x
	{0xBD,0x37,0x63,0x88,0xB5,0xF7,0x23,0xFB,0x4C,0x22,0xDF,0xE6,0xCD,0x43,0x75,0xA0,0x5A,0x07,0x47,0x64,0x44,0xD5,0x81,0x99,0x85,0x00,0x7E,0x34},	// y
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01},	// z
	{0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01},	//R^2 mod m
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE},	// A
	{0xB4,0x05,0x0A,0x85,0x0C,0x04,0xB3,0xAB,0xF5,0x41,0x32,0x56,0x50,0x44,0xB0,0xB7,0xD7,0xBF,0xD8,0xBA,0x27,0x0B,0x39,0x43,0x23,0x55,0xFF,0xB4},	// B
	{0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x16,0xA2,0xE0,0xB8,0xF0,0x3E,0x13,0xDD,0x29,0x45,0x5C,0x5C,0x2A,0x3D},	//order 32bytes
	"SECP_224R1",
   { 0xD4, 0xBA, 0xA4, 0xCF, 0x18, 0x22, 0xBC, 0x47, 0xB1, 0xE9, 0x79, 0x61, 0x6A, 0xD0, 0x9D, 0x91, 0x97, 0xA5, 0x45, 0x52, 0x6B, 0xDA, 0xAE, 0x6C, 0x3A, 0xD0, 0x12, 0x89, },
   { 0xF8, 0x61, 0xAC, 0x50, 0xD8, 0xEA, 0x6C, 0xEC, 0x38, 0x25, 0x44, 0x85, 0x29, 0xDE, 0xB3, 0x36, 0x6D, 0x62, 0x58, 0x7F, 0xD6, 0xE2, 0x42, 0x70, 0x6A, 0x1F, 0xC2, 0xEB, },
   { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x16, 0xA2, 0xE0, 0xB8, 0xF0, 0x3E, 0x13, 0xDD, 0x29, 0x45, 0x5C, 0x5C, 0x2A, 0x3D, },
};

static const EC_CURVE_DATA SEC224K1 = {
        28,
        {0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  //(next power 2)/2=2^223
        {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xE5,0x6D},  // modulus m (p), Prime-modulus:(p-or-m)
        {0xF2,0x88,0x96,0x42,0xDC,0x4E,0xED,0x3B,0x7A,0x95,0xBC,0x65,0x66,0xE2,0x85,0x52,0xEA,0x63,0x05,0x95,0x5A,0x92,0xA0,0x0A,0x19,0x8D,0x13,0x9B},  // m' ,modular inverse of m (mod R)
        {0xA1,0x45,0x5B,0x33,0x4D,0xF0,0x99,0xDF,0x30,0xFC,0x28,0xA1,0x69,0xA4,0x67,0xE9,0xE4,0x70,0x75,0xA9,0x0F,0x7E,0x65,0x0E,0xB6,0xB7,0xA4,0x5C},  // x
        {0x7E,0x08,0x9F,0xED,0x7F,0xBA,0x34,0x42,0x82,0xCA,0xFB,0xD6,0xF7,0xE3,0x19,0xF7,0xC0,0xB0,0xBD,0x59,0xE2,0xCA,0x4B,0xDB,0x55,0x6D,0x61,0xA5},  // y
        {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01},  // z
        {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x35,0x26,0x02,0xC2,0x30,0x69},  //R^2 mod m
        {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // A
        {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05},  // B
        {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xDC,0xE8,0xD2,0xEC,0x61,0x84,0xCA,0xF0,0xA9,0x71,0x76,0x9F,0xB1,0xF7},      //order 32bytes
        "SECP_224K1"
};

