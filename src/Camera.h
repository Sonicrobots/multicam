#ifndef MADCAM_CAMERA_H
#define MADCAM_CAMERA_H

#include "ofMain.h"
#include "Utils.h"


class Camera {
public:
  void update();
  void setup(int camWidth, int camHeight);
  void draw(float x, float y, float z, float w, float h, float sx, float sy, float sw, float sh);

  void trigger();
  void reset();

  void setFXMode(bool on);
  void setTriggerMode(bool on);
  void setDeviceID(int id);
  void setFPS(int fps);
  void setThreshold(float t);
protected:

private:
  static const int BUF_LEN = 512;

  bool useTrigger;

  int device;
  int fps;
  int decay;
  int position;
  float thresh;

  ofShader fx;
  ofVideoGrabber grabber;

  void initBuffer();

  unsigned char * pix;

  std::array<int, BUF_LEN> curve;
};

#endif
