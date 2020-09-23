# VideoWriter Class

``` c++
VideoWriter::VideoWriter(const String& filename, int fourcc, double fps, Size 								frameSize, bool isColor=true);
bool VideoWriter::open(const String& filename, int fourcc, double fps,
                      	Size frameSize, bool isColor=true);
```

- fourcc : 동영상 압축 코덱을 표현하는 4문자 코드
- fps : 저장할 동영상의 초당 프레임 수
- frameSize : 동영상 프레임의 가로 및 세로 크기
- isColor : true이면 컬러, false이면 그레이스케일로 영상 저장
- 반환값 : 열기가 성공하면 true,  실패하면 false



```c++
static int VideoWriter::fourcc(char c1, char c2, char c3, char c4);
```

- c1, c2, c3, c4 : 코덱을 표현하는 1byte 문자 4개
- 반환값 : 4-문자 코드

| fourcc 코드 생성 방법                   | 코덱 설명                  |
| --------------------------------------- | -------------------------- |
| VideoWriter::fourcc('D', 'I', 'V', 'X') | DivX MPEG-4코덱            |
| VideoWriter::fourcc('X', 'V', 'I', 'D') | XVID MEPG-4 코덱           |
| VideoWriter::fourcc('F', 'M', 'P', '4') | FFMPEG MPEG4 코덱          |
| VideoWriter::fourcc('W', 'M', 'V', '2') | Windows Media Video 8 코덱 |
| VideoWriter::fourcc('M', 'J', 'P', 'G') | 모션 JPEG 코덱             |
| VideoWriter::fourcc('Y', 'V', '1', '2') | YUV 4:2:0 Planar(비압축)   |
| VideoWriter::fourcc('X', '2', '6', '4') | H.264 / AVC 코덱           |
| VideoWriter::fourcc('A', 'V', 'C', '1') | Advanced Video 코덱        |



```c++
VideoWriter& VideoWriter::operator << (const Mat & image);
void VideoWriter::write(InputArray image);
```

- image : 추가할 프레임
- 열려 있는 동영상에 새로운 프레임을 추가



```c++
virtual void VideoWriter::release();
```

- 프레임 저장 완료 후 열려 있던 파일을 닫음