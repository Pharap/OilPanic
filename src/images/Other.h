
#pragma once

namespace Images {

    const uint8_t PROGMEM ThrowOil_LH[] = {
    4, 8,
    0x0c, 0x03, 0x30, 0x0c, 

    0x1b, 0x00, 0x1b, 0x00, 

    0x06, 0x18, 0x03, 0x0c, 
    };

    const uint8_t PROGMEM ThrowOil_RH[] = {
    4, 8,
    0x0c, 0x30, 0x03, 0x0c, 

    0x00, 0x1b, 0x00, 0x1b, 

    0x0c, 0x03, 0x18, 0x06, 
    };

    const uint8_t PROGMEM GameOver[] = {
    60, 14,
    0xff, 0x01, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0x0d, 0xf5, 0xb5, 0x2d, 0xfd, 0x0d, 0xb5, 0xb5, 0x0d, 0xfd, 0x05, 0xed, 0xdd, 0xed, 0x05, 0xfd, 0x05, 0xb5, 0xb5, 0xf5, 0xfd, 0xfd, 0xfd, 0x0d, 0xf5, 0xf5, 0x0d, 0xfd, 0x05, 0xfd, 0xfd, 0xfd, 0x05, 0xfd, 0x05, 0xb5, 0xb5, 0xf5, 0xfd, 0x05, 0xb5, 0xb5, 0x4d, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0x01, 0x07, 0xfc, 
    0x1f, 0x10, 0x37, 0x27, 0x27, 0x27, 0x27, 0x26, 0x25, 0x25, 0x26, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x24, 0x25, 0x25, 0x25, 0x27, 0x27, 0x27, 0x26, 0x25, 0x25, 0x26, 0x27, 0x27, 0x26, 0x25, 0x26, 0x27, 0x27, 0x24, 0x25, 0x25, 0x25, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x20, 0x20, 0x3f, 
    };

    const uint8_t PROGMEM GameOver_Mask[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
    0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
    };

    const uint8_t PROGMEM Font[] = {
    3, 8,
    0x1F, 0x11, 0x1F, // 0  
    0x00, 0x1F, 0x00,
    0x1D, 0x15, 0x17,  
    0x11, 0x15, 0x1F,  
    0x07, 0x04, 0x1F,  
    0x17, 0x15, 0x1D,  
    0x1F, 0x15, 0x1D,  
    0x01, 0x01, 0x1F,  
    0x1F, 0x15, 0x1F,  
    0x17, 0x15, 0x1F, // 9
    };
    

    const uint8_t PROGMEM Bystanders[] = {
    24, 24,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8f, 0x51, 0x20, 0x23, 0xc0, 0x23, 0x20, 0x51, 0x8f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x65, 0x18, 0x1c, 0x20, 0x40, 0x31, 0x40, 0x20, 0x1c, 0x18, 0x65, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x20, 0x50, 0x88, 0x11, 0x2f, 0x51, 0x20, 0x29, 0xc4, 0x29, 0x20, 0x51, 0x2f, 0x11, 0x88, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x1a, 0x1c, 0x20, 0x40, 0x31, 0x40, 0x20, 0x1c, 0x1a, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x40, 0xa0, 0x24, 0x4a, 0x51, 0x50, 0x22, 0x00, 0x00, 0x30, 0x4c, 0x88, 0x10, 0x0d, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x01, 0x4d, 0x33, 0x00, 0x70, 0x10, 0x21, 0x5f, 0x12, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xc8, 0x10, 0x64, 0x4a, 0x31, 0x10, 0x02, 0x20, 0x40, 0x90, 0x09, 0x21, 0x42, 0x34, 0x08, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x4d, 0x32, 0x00, 0x70, 0x10, 0x21, 0x5f, 0x12, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    };

    const uint8_t PROGMEM Bystanders_Mask[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8f, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x8f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x67, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x67, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x20, 0x70, 0xf8, 0xf1, 0xef, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xef, 0xf1, 0xf8, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x7b, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7b, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x40, 0xe0, 0xe4, 0xce, 0xdf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x8f, 0x1f, 0x0f, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x4d, 0x7f, 0x7f, 0x7f, 0x1f, 0x3f, 0x7f, 0x73, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xf8, 0xf0, 0xe4, 0xce, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x9f, 0x1f, 0x3f, 0x7e, 0x3c, 0x08, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x4d, 0x7f, 0x7f, 0x7f, 0x1f, 0x3f, 0x7f, 0x72, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    };

};