# OpenCV 주요 클래스

### Point_ 클래스

2차원 평면 위에 있는 점의 좌표를 표현하는 클래스

- `Point::dot()` 두 점 사이의 내적을 계산
- `Point::ddot()` 두 점 사이의 내적을 실수형으로 계산
- `Point::cross()` 두 점 사이의 외적을 반환
- `Point::inside()` 점의 좌표가 사각형 r안에 있으면 true 반환



### Size_ 클래스

영상 또는 사각형 영역의 크기를 표현하는 클래스

- `Size::area()` 사각형 크기에 해당하는 면적을 반환
- `Size::empty()` 유효하지 않은 크기이면 true 반환



### Rect_ 클래스

사각형의 위치와 크기 정보를 표현하는 클래스

- `Rect::tl()` 사각형의 좌측 상단 점의 좌표를 반환
- `Rect::br()` 사각형의 우측 하단 점의 좌표를 반환
- `Rect::size()` 사각형의 크기 정보를 반환
- `Rect::area()` 면적을 반환
- `Rect::empty()` 유효하지 않은 사각형이면 true 반환
- `Rect::contains` 인자로 전달된 pt점이 사각형 내부에 있으면 true 반환



### RotatedRect 클래스

회전된 사각형을 표현하는 클래스

사각형의 중심좌표 center, 가로 및 세로크기 size, 회전 각도 정보 angle 멤버 변수로 가짐

- `RotatedRect::points()` 회전된 사각형의 네 꼭지점 좌표를 pts인자에 저장
- `RotatedRect::boundingRect()` 회전된 사각형을 포함하는 최소 크기의 사각형 정보를 반환
- `RotatedRect::boundingRect2f()`



### Range 클래스

범위 또는 구간을 표현하는 클래스

- `Range::size()` 범위의 크기(end-start)를 반환
- `Range::empty()` start와 end가 같으면 true 반환
- `Range::all()` start=INT_MIN, end=INT_MAX로 설정한 Range객체를 반환