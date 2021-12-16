#include <Mouse.h>
#include <Wire.h>
#include <SPI.h>
     
#include <usbhub.h>
USB     Usb;

#include "KuaFu.h"
KuaFu kuaFu(&Usb);

int dX = 0;
int dY = 0;
int dZ = 0;

int lb = 0;
int rb = 0;
int mb = 0;
int nb = 0;
int pb = 0;


void setup() {
  Mouse.begin();
  Serial.begin(115200);
  Serial.setTimeout(1);
  Usb.Init();
}

void loop() {
  Usb.Task();

  if (kuaFu.connected()) {
    if (kuaFu.mi.dX || kuaFu.mi.dY)
    {
      Mouse.move(kuaFu.mi.dX, kuaFu.mi.dY);
    }
    if (kuaFu.mi.dZ)
    {
      Mouse.move(0,0,kuaFu.mi.dZ);
    }
    if (kuaFu.mi.bmLeftButton != lb)
    {
      Serial.println(lb);
      lb = kuaFu.mi.bmLeftButton;
      if (lb)
      {
        Mouse.press(MOUSE_LEFT);
      }
      else
      {
        Mouse.release(MOUSE_LEFT);
      }
    }
    if (kuaFu.mi.bmRightButton != rb)
    {
      rb = kuaFu.mi.bmRightButton;
      if (rb)
      {
        Mouse.press(MOUSE_RIGHT);
      }
      else
      {
        Mouse.release(MOUSE_RIGHT);
      }
    }
    if (kuaFu.mi.bmMiddleButton != mb)
    {
      mb = kuaFu.mi.bmMiddleButton;
      if (mb)
      {
        Mouse.press(MOUSE_MIDDLE);
      }
      else
      {
        Mouse.release(MOUSE_MIDDLE);
      }
    }
	
	
	//bmNextButton
	//bmPreviousButton
    

    kuaFu.mi.dX = 0;
    kuaFu.mi.dY = 0;
    kuaFu.mi.dZ = 0;
  }
}