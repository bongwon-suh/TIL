# Mat 클래스

행렬을 나타내는 Mat클래스는 2차원 행렬뿐만 아니라 고차원 행렬을 표현 할 수 있으며, 한 개 이상의 채널을 가질 수 있다. Mat클래스에는 정수, 실수, 복소수 등으로 구성된 행렬 또는 벡터를 저장할 수 있고 그레이스케일 또는 컬러 영상을 저장 할 수도 있고 벡터 필드, 포인트 클라우드, 텐서, 히스토그램 등 정보를 저장하는 용도로도 사용 할 수 있다.



### 행렬의 생성과 초기화

```c++
Mat::Mat(int rows, int cols, int type);
```

- rows : 행렬의 행 개수(영상의 세로 크기)
- cols : 행렬의 열 개수(영상의 가로 크기)
- type : 행렬의 타입

```c++
Mat img(480, 640, CV_8UC1);		// 1-channel 그레이스케일 영상
Mat img2(480, 640, CV_8UC3);	// 3-channel 트루컬러 영상
```



```c++
Mat::Mat(int rows, int cols, int type, const Scalar& s);
Mat::Mat(Size size, int type, const Scalar& s);
```

- rows : 행렬의 행 개수(영상의 세로 크기)

- cols : 행렬의 열 개수(영상의 가로 크기)

- size : 행렬의 크기

- type : 행렬의 타입

- s : 행렬 원소  초기값

  ```c++
  Mat img(480, 640, CV_8UC1, Scalar(128));	//그레이스케일
  Mat img(480, 640, CV_8UC3, Scalar(0,0,255));	//Red, BGR순서
  ```



```c++
static MatExpr Mat::zeros(int rows, int cols, int type);
static MatExpr Mat::zeros(Size size, int type);
```

모든 원소가 0으로 초기화된 행렬을 만드는 함수

- rows : 행렬의 행 개수(영상의 세로 크기)

- cols : 행렬의 열 개수(영상의 가로 크기)

- size : 행렬의 크기

- type : 행렬의 타입

- 반환값 : 모든 원소가 0으로 초기화된 행렬 표현식

  ```c++
  Mat mat = Mat::zeros(3, 3, CV_32SC1);	//0으로 초기화된 3x3행렬
  ```



```c++
static MatExpr Mat::ones(int rows, int cols, int type);
static MatExpr Mat::ones(Size size, int type)
```

모든 원소가 1로 초기화된 행렬을 만드는 함수



```c++
static MatExpr Mat::eye(int rows, int cols, int type);
static MatExpt Mat::eye(Size size, int type);
```

단위 행렬을 생성하는 함수



```c++
Mat::Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP);
Mat::Mat(Size size, int type, void* data, size_t step=AUTO_STEP);
```

- rows : 행렬의 행 개수(영상의 세로 크기)
- cols : 행렬의 열 개수(영상의 가로 크기)
- size : 행렬의 크기
- type : 행렬의 타입
- data : 사용할 행렬 데이터의 주소. 외부 데이터를 사용하여 객체를 생성할 경우, 생성자에서 원소 데이터 저장을 위한 메모리 공간을 동적으로 할당하지 않음
- step : (외부)행렬 데이터에서 한 행이 차지하는 바이트 수. 외부 행렬 데이터의 각 행에 여분의
  패딩바이트가 존재하면 명시적으로 지정해야함. AUTO_STEP은 패딩바이트가 없다고 간주



```c++
void Mat::create(int rows, int cols, int type);
void Mat::create(Size size, int type);
```

비어 있는 Mat 객체 또는 이미 생성된 Mat 객체에 새로운 행렬을 할당하는 함수

- rows : 행렬의 행 개수(영상의 세로 크기)
- cols : 행렬의 열 개수(영상의 가로 크기)
- size : 행렬의 크기
- type : 행렬의 타입



```c++
Mat& Mat::operator = (const Scalar& s);
Mat& Mat::setTo(InputArray value, InputArray mask = noArray());
```

Mat 클래스는 `=` 연산자 재정의 또는 `Mat::setTo()`함수를 이용하여 행렬 전체 원소 값을 한꺼번에 설정할 수 있음

- s : 행렬 원소에 설정할 값
- 반환값 : 값이 설정된 Mat 객체의 참조
- value : 행렬 원소에 설정할 값
- mask : 마스크 행렬. 마스크 행렬의 원소가 0이 아닌 위치에서만 value값이 설정
  행렬 전체 원소값을 설정하려면 noArray() 또는 Mat()을 지정
- 반환값 : Mat 객체의 참조



### 행렬의 복사

```c++
Mat Mat::clone() const;
```

- 반환값 : *this 행렬의 복사본

```c++
void Mat::copyTo(OutputArray m) const;
void Mat::copyTo(OutputArray m), InputArray const;
```

- m : 복사본이 저장될 행렬. 만약 *this 행렬과 크기 및 타입이 다르면 메모리를 새로 할당한 후 픽셀 값을 복사
- mask : 마스크 행렬. 행렬의 원소 값이 0이 아닌 좌표에서만 행렬 원소를 복사



### 부분 행렬 추출

```c++
Mat Mat::operator()(const Rect& roi) const;
Mat Mat::operator()(Range rowRange, Range colRange)const;
```

- roi : 사각형 관심영역
- rowRange : 관심 행 범위
- colRange : 관심 열 범위
- 반환값 : 추출한 부분 행렬 또는 영상. 부분 영상의 픽셀 데이터를 서로 공유

Mat 클래스의 괄호 연산자를 이용하여 얻은 부분 영상은 얕은 복사 형식이기 때문에 추출한 부분의 픽셀 값을 변경하면 원본 영상의 픽셀 값도 함께 변경



```c++
Mat Mat::rowRange(int startrow, int endrow) const;
Mat Mat::rowRange(const Range& r) const;
```

- startrow : 추출할 행 범위 시작번호
- endrow : 추출할 행 범위 끝번호
- r : 추출할 행 범위
- 반환값 : 지정한 행 범위에 해당하는 행렬

```c++
Mat Mat::colRange(int startcol, int endcol) const;
Mat Mat::colRange(const Range& r) const;
```

- startrow : 추출할 열 범위 시작번호
- endrow : 추출할 열 범위 끝번호
- r : 추출할 열 범위
- 반환값 : 지정한 열 범위에 해당하는 행렬

Mat행렬에서 특정 범위의 행 또는 열을 부분 행렬로 추출하고자 할 때 사용



```c++
Mat Mat::row(int y) const;
Mat Mat::col(int x) const;
```

- y : 부분행렬로 추출할 행 번호
- x : 부분행렬로 추출할 열 번호
- 반환값 추출할 부분 행렬(얕은 복사)

Mat행렬로부터 하나의 행 또는 열을 추출하여 1행짜리 또는 1열짜리 행렬을 만듬

