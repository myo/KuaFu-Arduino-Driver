#ifndef __kuafu_h__
#define __kuafu_h__

#include <hiduniversal.h>

//length of data packet should always be 6 bytes!
//if it is not some other device is sending data
//to our endpoint
struct MOUSEINFO {

        struct {
                uint8_t bmLeftButton : 1; //1
                uint8_t bmRightButton : 1; //2
                uint8_t bmMiddleButton : 1; //4
                uint8_t bmPreviousButton : 1; //8
				uint8_t bmNextButton : 1; //16
				uint8_t padding1 : 3; //32, 64, 128
        };
		int16_t dX : 12; //all 8 bits from 2nd byte, 4 from 3rd byte
		int16_t dY : 12; //4 bits from 3rd byte and 8 from 4th byte
		int8_t dZ; //the 5th byte is the scroll wheel: 0x1 = up, 0xff = down, 0 = no action
		int8_t ACPan; //6th and last byte is always 00
};
class KuaFu : public HIDUniversal {
public:
	KuaFu(USB *p) : HIDUniversal(p) {};
	bool connected() {
		return HIDUniversal::isReady();
	}
	MOUSEINFO mi;
private:
	void ParseHIDData(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf); // Called by the HIDUniversal library
    uint8_t OnInitSuccessful() { return 0; }; // Called by the HIDUniversal library, 0 is success, -1 is error.
};
#endif