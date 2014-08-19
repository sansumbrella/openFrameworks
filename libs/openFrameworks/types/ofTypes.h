#pragma once

#include "ofConstants.h"
#include "ofColor.h"

#include <memory>


//----------------------------------------------------------
// ofDeviceInfo
//----------------------------------------------------------
class ofSerial;
class ofSerialDeviceInfo{
	friend class ofSerial;

	public:

		ofSerialDeviceInfo(string devicePathIn, string deviceNameIn, int deviceIDIn){
			devicePath			= devicePathIn;
			deviceName			= deviceNameIn;
			deviceID			= deviceIDIn;
		}

		ofSerialDeviceInfo(){
			deviceName = "device undefined";
			deviceID   = -1;
		}

		string getDevicePath(){
			return devicePath;
		}

		string getDeviceName(){
			return deviceName;
		}

		int getDeviceID(){
			return deviceID;
		}

	protected:
		string devicePath;			//eg: /dev/tty.cu/usbdevice-a440
		string deviceName;			//eg: usbdevice-a440 / COM4
		int deviceID;				//eg: 0,1,2,3 etc

		//TODO: other stuff for serial ?
};


//----------------------------------------------------------
// ofMutex
//----------------------------------------------------------

#include "Poco/Mutex.h"
typedef Poco::FastMutex ofMutex;
typedef Poco::FastMutex::ScopedLock ofScopedLock;

//----------------------------------------------------------
// ofStyle
//----------------------------------------------------------

class ofStyle{
	public:
		ofStyle(){
			bFill				= true;
			blendingMode		= OF_BLENDMODE_DISABLED;
			smoothing			= false;
			circleResolution	= 20;
			sphereResolution	= 20;
			curveResolution		= 20;
			lineWidth			= 1.0;
			polyMode			= OF_POLY_WINDING_ODD;
			rectMode			= OF_RECTMODE_CORNER;
			#ifdef TARGET_OPENGLES
				drawBitmapMode		= OF_BITMAPMODE_SIMPLE;
			#else
				drawBitmapMode		= OF_BITMAPMODE_MODEL_BILLBOARD;
			#endif
			bgColor.set(200,200,200);
			//depthTest = false;
		}

		virtual ~ofStyle(){}

		ofColor color;
		ofColor bgColor;
		ofPolyWindingMode polyMode;
		ofRectMode rectMode;
		bool bFill;
		ofDrawBitmapMode drawBitmapMode;

		ofBlendMode blendingMode;

		bool smoothing;
		int circleResolution;
		int sphereResolution;
		int curveResolution;
		float lineWidth;
		//bool depthTest; removed since it'll break old projects setting depth test through glEnable
};

class ofVideoFormat{
public:
	  ofPixelFormat pixelFormat;
	  int    width;
	  int    height;
	  vector<float> framerates;
};

class ofVideoDevice{
public:
	  int id;
	  string deviceName;
	  string hardwareName;
	  vector<ofVideoFormat> formats;
      bool bAvailable;
};
