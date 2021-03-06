/*
This work is licensed under the Creative Commons Attribution 3.0 Unported License.
To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/
or send a letter to
	Creative Commons,
	171 Second Street,
	Suite 300,
	San Francisco,
	California,
	94105,
	USA.
*/

#ifndef __DESCRIPTORS_H__
#define __DESCRIPTORS_H__

#include "usb_stack.h"

#pragma romdata
const unsigned char usb_device_descriptor[] = {
	0x12,								// bLength
	USB_DEVICE_DESCRIPTOR_TYPE,			// bDescriptorType
	0x10,								// bcdUSB (low byte)
	0x01,								// bcdUSB (high byte)
	0x02,								// bDeviceClass
	0x00,								// bDeviceSubClass
	0x00,								// bDeviceProtocol
	USB_MAX_BUFFER_SIZE,				// bMaxPacketSize
	LOWB(USB_VID),						// idVendor (low byte)
	HIGHB(USB_VID),						// idVendor (high byte)
	LOWB(USB_PID),						// idProduct (low byte)
	HIGHB(USB_PID),						// idProduct (high byte)
	LOWB(USB_DEV),						// bcdDevice (low byte)
	HIGHB(USB_DEV),						// bcdDevice (high byte)
	USB_iManufacturer,					// iManufacturer
	USB_iProduct,						// iProduct
	USB_iSerialNum,						// iSerialNumber (none)
	USB_NUM_CONFIGURATIONS				// bNumConfigurations 
};

#define USB_CONFIG_DESC_TOT_LENGTH (9+9+5+4+5+5+7+9+7+7)
const unsigned char usb_config_descriptor[] = {
	0x09,								// bLength
	USB_CONFIGURATION_DESCRIPTOR_TYPE,	// bDescriptorType
	LOWB(USB_CONFIG_DESC_TOT_LENGTH),	// wTotalLength (low byte), TODO: Automatic calculation - sizeof doesn't work here
	HIGHB(USB_CONFIG_DESC_TOT_LENGTH),	// wTotalLength (high byte)
	USB_NUM_INTERFACES,					// bNumInterfaces
	0x01,								// bConfigurationValue
	0x00,								// iConfiguration (0=none)
	0x80,								// bmAttributes
	0x32,								// bMaxPower (in 2 mA units, 50=100 mA)

	0x09,								// bLength (Interface0 descriptor starts here)
	USB_INTERFACE_DESCRIPTOR_TYPE,		// bDescriptorType
	0x00,								// bInterfaceNumber
	0x00,								// bAlternateSetting
	0x01,								// bNumEndpoints (excluding EP0)
	0x02,								// bInterfaceClass (0x00=per endpoint specified, 0xFF=vendor specific)
	0x02,								// bInterfaceSubClass (0x00=per endpoint specified, 0xFF=vendor specific)
	0x00,								// bInterfaceProtocol
	0x00,								// iInterface (none)

	0x05,								// bFunctionLength (CDC header descriptor)
	0x24,								// bDescriptorType
	0x00,								// bDescriptorSubtype
	0x10,								// bcdCDC (low byte)
	0x01,								// bcdCDC (high byte)

	0x04,								// bFunctionLength (CDC abstract control management descriptor)
	0x24,								// bDescriptorType
	0x02,								// bDescriptorSubtype
	0x02,								// bmCapabilities

	0x05,								// bFunctionLength (CDC union descriptor)
	0x24,								// bDescriptorType
	0x06,								// bDescriptorSubtype
	0x00,								// bControlInterface
	0x01,								// bSubordinateInterface0

	0x05,								// bFunctionLength (PSTN call management descriptor)
	0x24,								// bDescriptorType
	0x01,								// bDescriptorSubtype
	0x01,								// bmCapabilities
	0x01,								// bInterfaceNum

	0x07,								// bLength (Endpoint1 descriptor)
	USB_ENDPOINT_DESCRIPTOR_TYPE,		// bDescriptorType
	0x81,								// bEndpointAddress
	0x03,								// bmAttributes (0x03=intr)
	0x10,								// wMaxPacketSize (low byte)
	0x00,								// wMaxPacketSize (high byte)
	0x40,								// bInterval

	0x09,								// bLength (Interface1 descriptor)
	USB_INTERFACE_DESCRIPTOR_TYPE,		// bDescriptorType
	0x01,								// bInterfaceNumber
	0x00,								// bAlternateSetting
	0x02,								// bNumEndpoints
	0x0A,								// bInterfaceClass
	0x00,								// bInterfaceSubClass
	0x00,								// bInterfaceProtocol
	0x00,								// iInterface

	0x07,								// bLength (Enpoint2 descriptor)
	USB_ENDPOINT_DESCRIPTOR_TYPE,		// bDescriptorType
	0x02,								// bEndpointAddress
	0x02,								// bmAttributes (0x02=bulk)
	0x20,								// wMaxPacketSize (low byte)
	0x00,								// wMaxPacketSize (high byte)
	0x00,								// bInterval

	0x07,								// bLength
	USB_ENDPOINT_DESCRIPTOR_TYPE,		// bDescriptorType
	0x83,								// bEndpointAddress
	0x02,								// bmAttributes (0x02=bulk)
	0x20,								// wMaxPacketSize (low byte)
	0x00,								// wMaxPacketSize (high byte)
	0x00								// bInterval
};

/* TODO: Develop prebuild script for generating all complex structures */

#endif//__DESCRIPTORS_H__
