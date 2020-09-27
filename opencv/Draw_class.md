# 다양한 그리기 함수

``` c++
void line(InputOutputArray img, Point pt1, Point pt2, const Scalar& color int 					thickness=1, int lineType=LINE_8, int shift=0);
```

- img : 입출력 영상
- pt1 : 시작점
- pt2 : 끝점
- color : 선 색상
- thickness : 선 두께
- lineType : 선 타입
- shift : 그리기 좌표값의 축소 비율



```c++
void arrowedLine(InputOutputArray img, Point pt1, Point pt2, const Scalar& color int 					thickness=1, int lineType=8, int shift=0, double tipLength=0.1);
```

- tipLength : 전체 직선 길이에 대한 화살표 길이의 비율



```c++
void DrawMarker(InputOutputArray img, Point position, const Scalar& color, int 				markerType=MARKER_CROSS, int markerSize=20, thickness=1, int lineType=8);
```

- position : 마커 출력 위치
- markerType : 마커 종류
- markerSize : 마커 크기

| markerType 열거형 상수 | 설명                                             |
| ---------------------- | ------------------------------------------------ |
| MARKER_CROSS           | 십자가 모양                                      |
| MARKER_TILTED_CROSS    | 45도 회전된 십자가 모양                          |
| MARKER_STAR            | MARKER_CROSS와 MARKER_TILTED_CROSS가 합쳐진 모양 |
| MARKER_DIAMOND         | 마름모 모양                                      |
| MARKER_SQUARE          | 정사각형 모양                                    |
| MARKER_TRIANGLE_UP     | 위로 뾰족한 삼각형 모양                          |
| MARKER_TRIANGLE_DOWN   | 아래로 뾰족한 삼각형 모양                        |



```c++
void rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=LINE_8, int shift=0);
void rectangle(InputOutputArray img, Rect rec, const Scalar& color, int thickness=1, int lineType=LINE_8, int shift=0);
```

- pt1 : 사각형 꼭지좀 좌표
- pt2 : pt1 과 대각 방향에 있는 사각형 꼭지점 좌표
- rec : 사각형 위치 정보
- color : 사각형 색상
- thickness : 사각형 외곽선 두께
- shift : 그리기 좌표 값의 축소 비율



```c++
void circle(InputOutputArray img, Point center, int radius, const Scalar& color, int thickness=1, int lineType=LINE_8, int shift=0);
```

- center 원의 중심
- radius : 원의 반지름
- color : 원 색상



```c++
void ellipse(InputOutputArray img, Point Center, Size axes, double angle, double startAngle, double endAngle, const Scalar& color, int thickness=1, int lineType=LINE_8, shift=0);
```

- axes : 타원의 반지름 Size (x축 반지름, y축 반지름)
- angle : 타원 회전 각도 (x축 기준 시계방향)
- startAngle : 타원 호의 시작 각도
- endAngle : 타원 호의 끝 각도



``` c++
void polylines(InputOutputArray img, InputArrayOfArrays pts, bool isClosed, const Scalar& color, int thickness=1, lineType=LINE_8, int shift=0);
```

- pts : 다각형 외곽 점들의 좌표 배열
- isClosed : 다각형이 닫혀 있는지를 나타내는 플래그



