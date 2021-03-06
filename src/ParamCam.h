#pragma once

#include "ofMain.h"
#include "Camera.h"

namespace ofxPvAPI {
	
	class ParamCam : public Camera {
	
	public:
		ParamCam() : bIpParametersEnabled(false) {;}
		virtual ~ParamCam() {;}
		
		void	setup();
		void	update();
		
		ofParameterGroup& getParameters() { return parameters; }
		
		//-- GENERAL -----------------------------------------------------------------
	protected:
		ofParameterGroup	parameters;
		
		ofParameter<bool>	printAttributes;
		ofParameter<bool>	reset;
		ofParameter<bool>	pActivate;
		ofParameter<bool>	pDeactivate;
		
		void	printAttributesListener(bool & _value)			{ if(!blockListeners && _value) listAttributes(); _value = false; }
		void	resetListener(bool & _value)					{ if(!blockListeners && _value) { resetAttributes(); setAllParametersFromCam(); } _value = false; }
		void	activateListener(bool& _value) { if (_value)	{ activate(); _value = false; } }
		void	deactivateListener(bool& _value) { if (_value)	{ deactivate(); _value = false; } }
		
		//-- FRAMES ------------------------------------------------------------------
	public:
		void	setFrameRate(float _value)	{ inRange(pFrameRate, _value); pFrameRate.set(_value); }
		void	setFrameOffset(int _value)	{ pFrameOffset.set(_value); }
		
	protected:
		ofParameterGroup	frameRateParameters;
		ofParameter<float>	pFrameRate;
		ofParameter<int>	pFrameOffset;
		ofParameter<int>	pFrameDrop;
		ofParameterGroup	latencyParameters;
		ofParameter<int>	pFrameLatency;
		ofParameter<int>	pFrameMaxLatency;
		ofParameter<int>	pFrameMinLatency;
		
		void	frameRateListener(float& _value);
		void	frameOffsetListener(int& _value);
		
		//-- REGION OF INTEREST ------------------------------------------------------
	public:
		void	setROIWidth(int _value)		{ inRange(pROIWidth, _value); pROIWidth.set(_value); }
		void	setROIHeight(int _value)	{ inRange(pROIHeight, _value); pROIHeight.set(_value); }
		void	setROIX(int _value)			{ inRange(pROIX, _value); pROIX.set(_value); }
		void	setROIY(int _value)			{ inRange(pROIY, _value); pROIY.set(_value); }
		
	protected:
		ofParameterGroup	roiParameters;
		ofParameter<int>	pROIWidth;
		ofParameter<int>	pROIHeight;
		ofParameter<int>	pROIX;
		ofParameter<int>	pROIY;
		
		void	ROIWidthListener(int& _value);
		void	ROIHeightListener(int& _value);
		void	ROIXListener(int& _value);
		void	ROIYListener(int& _value);
		
		//-- EXPOSURE ----------------------------------------------------------------
	public:
		void	setExposure(int _value)						{ inRange(pExposure, _value); pExposure.set(_value); }
		void	setAutoExposure(bool _value)				{ pAutoExposure.set(_value); }
		void	setAutoExposureOnce(bool _value)			{ pAutoExposureOnce.set(_value); }
		void	setAutoExposureTarget(int _value)			{ inRange(pAutoExposureTarget, _value); pAutoExposureTarget.set(_value); }
		void	setAutoExposureRate(int _value)				{ inRange(pAutoExposureRate, _value); pAutoExposureRate.set(_value); }
		void	setAutoExposureAdjustTol(int _value)		{ inRange(pAutoExposureAdjustTol, _value); pAutoExposureAdjustTol.set(_value); }
		void	setAutoExposureOutliers(int _value)			{ inRange(pAutoExposureOutliers, _value); pAutoExposureOutliers.set(_value); }
		void	setAutoExposureMinimum(int _value)			{ inRange(pAutoExposureMinimum, _value); pAutoExposureMinimum.set(_value); }
		void	setAutoExposureMaximum(int _value)			{ inRange(pAutoExposureMaximum, _value); pAutoExposureMaximum.set(_value); }
		
	protected:
		ofParameterGroup	exposureParameters;
		ofParameterGroup	autoExposureParameters;
		ofParameter<int>	pExposure;
		ofParameter<bool>	pAutoExposure;
		ofParameter<bool>	pAutoExposureOnce;
		ofParameter<int>	pAutoExposureTarget;
		ofParameter<int>	pAutoExposureRate;
		ofParameter<int>	pAutoExposureAdjustTol;
		ofParameter<int>	pAutoExposureOutliers;
		ofParameter<int>	pAutoExposureMinimum;
		ofParameter<int>	pAutoExposureMaximum;
		
		void	exposureListener(int& _value)				{ if(!blockListeners) Camera::setExposure(_value); }
		void	autoExposureOnceListener(bool& _value)		{ if(!blockListeners) Camera::setAutoExposureOnce(_value); }
		void	autoExposureListener(bool& _value)			{ if(!blockListeners) Camera::setAutoExposure(_value); }
		void	autoExposureTargetListener(int& _value)		{ if(!blockListeners) Camera::setAutoExposureTarget(_value); }
		void	autoExposureRateListener(int& _value)		{ if(!blockListeners) Camera::setAutoExposureRate(_value); }
		void	autoExposureAdjustTolListener(int& _value)	{ if(!blockListeners) Camera::setAutoExposureAdjustTol(_value); }
		void	autoExposureOutliersListener(int& _value)	{ if(!blockListeners) Camera::setAutoExposureOutliers(_value); }
		void	autoExposureMinimumListener(int& _value)	{ if(!blockListeners) Camera::setAutoExposureMinimum(_value); }
		void	autoExposureMaximumListener(int& _value)	{ if(!blockListeners) Camera::setAutoExposureMaximum(_value); }
		
		//-- GAIN --------------------------------------------------------------------
	public:
		void	setGain(int _value)							{ inRange(pGain, _value); pGain.set(_value); }
		void	setAutoGain(bool _value)					{ pAutoGain.set(_value); }
		void	setAutoGainOnce(bool _value)				{ pAutoGainOnce.set(_value); }
		void	setAutoGainTarget(int _value)				{ inRange(pAutoGainTarget, _value); pAutoGainTarget.set(_value); }
		void	setAutoGainRate(int _value)					{ inRange(pAutoGainRate, _value); pAutoGainRate.set(_value); }
		void	setAutoGainAdjustTol(int _value)			{ inRange(pAutoGainAdjustTol, _value); pAutoGainAdjustTol.set(_value); }
		void	setAutoGainOutliers(int _value)				{ inRange(pAutoGainOutliers, _value); pAutoGainOutliers.set(_value); }
		void	setAutoGainMinimum(int _value)				{ inRange(pAutoGainMinimum, _value); pAutoGainMinimum.set(_value); }
		void	setAutoGainMaximum(int _value)				{ inRange(pAutoGainMaximum, _value); pAutoGainMaximum.set(_value); }
		
	protected:
		ofParameterGroup	gainParameters;
		ofParameterGroup	autoGainParameters;
		ofParameter<int>	pGain;
		ofParameter<bool>	pAutoGain;
		ofParameter<bool>	pAutoGainOnce;
		ofParameter<int>	pAutoGainTarget;
		ofParameter<int>	pAutoGainRate;
		ofParameter<int>	pAutoGainAdjustTol;
		ofParameter<int>	pAutoGainOutliers;
		ofParameter<int>	pAutoGainMinimum;
		ofParameter<int>	pAutoGainMaximum;
		
		void	gainListener(int& _value)					{ if(!blockListeners) Camera::setGain(_value); }
		void	autoGainListener(bool& _value)				{ if(!blockListeners) Camera::setAutoGain(_value); }
		void	autoGainOnceListener(bool& _value)			{ if(!blockListeners) Camera::setAutoGainOnce(_value); }
		void	autoGainTargetListener(int& _value)			{ if(!blockListeners) Camera::setAutoGainTarget(_value); }
		void	autoGainRateListener(int& _value)			{ if(!blockListeners) Camera::setAutoGainRate(_value); }
		void	autoGainAdjustTolListener(int& _value)		{ if(!blockListeners) Camera::setAutoGainAdjustTol(_value); }
		void	autoGainOutliersListener(int& _value)		{ if(!blockListeners) Camera::setAutoGainOutliers(_value); }
		void	autoGainMinimumListener(int& _value)		{ if(!blockListeners) Camera::setAutoGainMinimum(_value); }
		void	autoGainMaximumListener(int& _value)		{ if(!blockListeners) Camera::setAutoGainMaximum(_value); }
		
		//-- GAMMA HUE STURATION -----------------------------------------------------
	public:
		void	setGamma(float _value)						{ inRange(pGamma, _value); pGamma.set(_value); }
		void	setHue(float _value)						{ inRange(pHue, _value); pHue.set(_value); }
		void	setSaturation(float _value)					{ inRange(pSaturation, _value); pSaturation.set(_value); }
		
	protected:
		ofParameterGroup	gammaHueSaturationParameters;
		ofParameter<float>	pGamma;
		ofParameter<float>	pHue;
		ofParameter<float>	pSaturation;
		
		void	gammaListener(float& _value)				{ if(!blockListeners) Camera::setGamma(_value); }
		void	hueListener(float& _value)					{ if(!blockListeners) Camera::setHue(_value); }
		void	saturationListener(float& _value)			{ if(!blockListeners) Camera::setSaturation(_value); }
		
		//-- WHITEBALANCE ------------------------------------------------------------
	public:
		void	setWhiteBalanceBlue(int _value)				{ inRange(pWhiteBalanceRed, _value); pWhiteBalanceRed.set(_value); }
		void	setWhiteBalanceRed(int _value)				{ inRange(pWhiteBalanceBlue, _value); pWhiteBalanceBlue.set(_value); }
		void	setAutoWhiteBalance(bool _value)			{ pAutoWhiteBalance.set(_value); }
		void	setAutoWhiteBalanceOnce(bool _value)		{ pAutoWhiteBalanceOnce.set(_value); }
		void	setAutoWhiteBalanceRate(int _value)			{ inRange(pAutoWhiteBalanceRate, _value); pAutoWhiteBalanceRate.set(_value); }
		void	setAutoWhiteBalanceAdjustTol(int _value)	{ inRange(pAutoWhiteBalanceAdjustTol, _value); pAutoWhiteBalanceAdjustTol.set(_value); }
		
	protected:
		ofParameterGroup	whiteBalanceParameters;
		ofParameterGroup	autoWhiteBalanceParameters;
		ofParameter<int>	pWhiteBalanceRed;
		ofParameter<int>	pWhiteBalanceBlue;
		ofParameter<bool>	pAutoWhiteBalance;
		ofParameter<bool>	pAutoWhiteBalanceOnce;
		ofParameter<int>	pAutoWhiteBalanceRate;
		ofParameter<int>	pAutoWhiteBalanceAdjustTol;
		
		void	WhiteBalanceRedListener(int& _value)		{ if(!blockListeners) Camera::setWhiteBalanceRed(_value); }
		void	WhiteBalanceBlueListener(int& _value)		{ if(!blockListeners) Camera::setWhiteBalanceBlue(_value); }
		void	autoWhiteBalanceListener(bool& _value)		{ if(!blockListeners) Camera::setAutoWhiteBalance(_value); }
		void	autoWhiteBalanceOnceListener(bool& _value)	{ if(!blockListeners) Camera::setAutoWhiteBalanceOnce(_value); }
		void	autoWhiteBalanceRateListener(int& _value)	{ if(!blockListeners) Camera::setAutoWhiteBalanceRate(_value); }
		void	autoWhiteBalanceAdjustTolListener(int& _value) { if(!blockListeners) Camera::setAutoWhiteBalanceAdjustTol(_value); }
		
		//-- IP SETTINGS -------------------------------------------------------------
	public:
		void	enableIPSettings();
		bool	getIPSettingsEnabled() { return bIpParametersEnabled; }
		
		void	setIpPersistent(bool _value) { pPersistentIpSwitch.set(_value); }
		void	setPersistentIpAdress(string _value);
		void	setPersistentIpSubnetMask(string _value);
		void	setPersistentIpGateway(string _value);
		
	protected:
		
		ofParameterGroup	ipParameters;
		ofParameter<string>	pCurrentIpPersistent;
		ofParameter<string>	pCurrentIpAdress;
		ofParameter<string>	pCurrentIpSubnetMask;
		ofParameter<string>	pCurrentIpGateway;
		
		bool				bIpParametersEnabled;
		ofParameterGroup	ipPersistentParameters;
		ofParameter<bool>	pPersistentIpSwitch;
		ofParameter<string>	pPersistentIpAdress;
		ofParameter<string>	pPersistentIpSubnetMask;
		ofParameter<string>	pPersistentIpGateway;
		ofParameter<bool>	pPersistentIpUpdate;
		
		void	pPersistentIpSwitchListener(bool & _value);
		void	pPersistentIpUpdateListener(bool & _value);
		
		//-- GENERAL -----------------------------------------------------------------
		void	updateParametersFromCam();
		void	setAllParametersFromCam();
		void	setAllParametersFromInterface();
		
		void	setParametersRange();
		void	setParameterInItsOwnRange(ofParameter<int> &_parameter);
		void	setParameterInItsOwnRange(ofParameter<float> &_parameter);
		
		bool	bLoadFromInterface;
		bool	blockListeners;
		
		void	inRange(ofParameter<int>& _parameter, int& _value);
		void	inRange(ofParameter<float>& _parameter, float& _value);
	};
}
