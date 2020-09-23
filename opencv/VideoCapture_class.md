# VideoCapture Class

```c++
VideoCapture::VideoCapture(const String& filename, int apiPreference = CAP_ANY);
bool VideoCapture::open(const String& filename, int apiPreference = CAP_ANY);
```

- apiPreference : 사용할 비디오 캡쳐 API 백엔드
- 반환값 : 열기가 성공하면 true, 실패시 false

| VideoCaputreAPIs 열거형 상수             | 설명                                |
| ---------------------------------------- | ----------------------------------- |
| CAP_ANY                                  | 자동선택                            |
| CAP_V4L, CAP_V4L2                        | V4L / V4L2 (리눅스)                 |
| CAP_FIREWIRE, CAP_FIREWARE, CAP_IEEE1394 | IEEE 1394 드라이버                  |
| CAP_DSHOW                                | 다이렉트쇼                          |
| CAP_PVAPI                                | PvAPI, Prosilia GigE SDK            |
| CAP_OPENNI                               | OpenNI                              |
| CAP_MSMF                                 | 마이크로소프트 미디어 파운데이션    |
| CAP_GSTREAMER                            | GStreamer                           |
| CAP_FFMPEG                               | FFMPEG 라이브러리                   |
| CAP_IMAGES                               | OpenCV에서 지원하는 일련의 영상파일 |
| CAP_OPENCV_MJPEG                         | OpenCV에 내장된 MotionJPEG 코덱     |



```c++
bool VideoCapture::isOpened() const;
```

- 반환값 : 카메라 또는 동영상 파일이 사용 가능하면 true, 아니면 false



```c++
virtual void VideoCapture::release();
```

- 카메라 장치 또는 동영상 파일의 사용이 끝나면 `VideoCapture::release();` 함수를 호출하여 사용하던 자원을 해제



```c++
VideoCapture& VideoCapture::operator >> (Mat& image);
bool VideoCapture::read(OutputArray image);
```

- image : 다음 비디오 프레임. 만약 더 가져올 프레임이 없다면 비어 있는 행렬로 설정
- 반환값 : 프레임을 받아 올 수 없으면 false
- VideoCapture 클래스에서 한 프레임을 받아 오기 위해서는 `VideoCapture::operator >>()` 연산자 재정의 함수 또는 `VideoCapture::read()` 함수 사용



```c++
double VideoCapture::get(int propId) const;
```

- propId : 속성 ID
- 반환값 : 지정한 속성 값

| VideoCaptureProperties 열거형 상수 | 설명                                               |
| ---------------------------------- | -------------------------------------------------- |
| CAP_PROP_POS_MSEC                  | 비디오 파일에서 현재 위치                          |
| CAP_PROP_POS_FRAMES                | 현재 프레임 위치                                   |
| CAP_PROP_POS_AVI_RATIO             | [0, 1] 구간으로 표현한 동영상 프레임의 상대적 위치 |
| CAP_PROP_FRAME_WIDTH               | 비디오 프레임의 가로 크기                          |
| CAP_PROP_FRAME_HEIGHT              | 비디오 프레임의 세로 크기                          |
| CAP_PROP_FPS                       | 초당 프레임 수                                     |
| CAP_PROP_FOURCC                    | fourcc 코드(코덱을 표현하는 정수값)                |
| CAP_PROP_FRAME_COUNT               | 비디오 파일의 전체 프레임 수                       |
| CAP_PROP_BRIGHTNESS                | 밝기 조절                                          |
| CAP_PROP_CONTRAST                  | 명암비 조절                                        |
| CAP_PROP_SATURATION                | 채도 조절                                          |
| CAP_PROP_HUE                       | 색상 조절                                          |
| CAP_PROP_GAIN                      | 감도 조절                                          |
| CAP_PROP_EXPOSURE                  | 노출 조절                                          |
| CAP_PROP_ZOOM                      | 줌 조절                                            |
| CAP_PROP_FOCUS                     | 초점 조절                                          |



```c++
bool VideoCapture::set(int propId, double value);
```

- propId : 속성 id
- value : 지정할 속성 값
- 반환값 : 속성 지정이 가능하면 true, 아니면 false
- 현재 열려 있는 카메라 또는 비디오 파일 재생과 관련된 속성 값을 설정



