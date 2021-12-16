#include "KuaFu.h"

void KuaFu::ParseHIDData(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {
		if (len == 6)
			memcpy(&mi, buf, min(len, MFK_CASTUINT8T sizeof(mi)));
}