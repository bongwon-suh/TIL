# InputArray 클래스

Mat, vector<T>등 다양한 타입을 표현 할 수 있는 인터페이스 클래스

```c++
Mat _IntputArray::getMat(int idx=-1) const;
```

- idx : 참조할 행 번호
- 반환값 : Mat 행렬 객체



# OutputArray 클래스

OpenCV 함수는 영상을 입력으로 받아 영상 처리를 수행하고, 그 결과를 다시 영상으로 생성하여 반환하는데 return구문으로 반환하는것이 아니라 OutputArray 클래스의 참조를 함수 인자로 사용하여 결과 영상을 전달

`typedef const _OutputArray& OutputArray;`