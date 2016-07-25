// Jaguar Land Rover - OSTC
// Simulator Seat CAN heartbeat generator.
// Author: Jesse Banks JBANKS2
// Designed for use with Arduino Uno (clone) and MCP2515 CAN-BUS shield
// https://www.amazon.com/Arduino-UNO-board-ATmega328P-A000066/dp/B008GRTSV6
// https://www.amazon.com/CAN-BUS-Shield-Compatible-Arduino-Seeeduino/dp/B00NQVH666
// Requires download and import of CANBUS library. found on github:
// https://github.com/coryjfowler/MCP_CAN_lib

#include <mcp_can.h>
#include <SPI.h>

byte ADR1 = 0xB8;
byte MSG1[8] = {0x20, 0x04, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

byte ADR2 = 0x80;
byte MSG2[8] = {0x00, 0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

MCP_CAN CAN0(10);     // Set CS to pin 10

void setup()
{
  // Initialize MCP2515 running at 16MHz with a baudrate of 125kb/s and the masks and filters disabled.
  CAN0.begin(MCP_ANY, CAN_125KBPS, MCP_16MHZ) == CAN_OK;
  
  // Change to normal mode to allow messages to be transmitted
  CAN0.setMode(MCP_NORMAL);   
}

void loop()
{
  CAN0.sendMsgBuf(ADR1, 0, 8, MSG1);
  CAN0.sendMsgBuf(ADR2, 0, 8, MSG2);
  delay(60);   // send data per 60ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
