# 산술 연산

영상은 일종의 2차원 행렬이기에 행렬 산술 연산이 가능하다.

```c++
void add(InputArray src1, InputArray src2, OutputArray dst, InputArray mask=noArray()
         int dtype=-1);
```

- src1 : 첫 번째 입력 행렬
- src2 : 두 번째 입력 행렬
- dst : 입력 행렬과 같은 크기, 같은 채널 수를 갖는 출력 행렬
- mask : 8비트 1채널 마스크 영상
- dtype : 출력 행렬의 깊이



```c++
void addWeighted(InputArray src1, double alpha, InputArray src2, double beta,
                 double gamma, OutputArray dst, int dtype=-1)
```

- src1 : 첫 번째 입력 행렬
- alpha : src1 행렬의 가중치
- src2 : 두 번째 입력행렬. src1과 크기와 채널이 같아야 함
- beta : src2 행렬의 가중치
- gamma : 가중합 결과에 추가적으로 더할 값
- dst : 출력 행렬
- dtype : 출력 행렬의 깊이



```c++
void subtract(InputArray src1, InputArray src2, OutputArray dst, 
              InputArray mask=noArray(), int dtype=-1);
```



```c++
void absdiff(InputArray src1, InputArray src2, OutputArray dst);
```



```c++
void multiply(InputArray src1, InputArray src2, OutputArray dst, double sclae=1,
              int dtye=-1);
```

- scale : 추가적으로 확대/축소할 비율

  

```c++
void divide(InputArray src1, InputArray src2, OutputArray dst, double src=1,
            int dtype=-1);
```





# 논리 연산

```c++
void bitwise_and(InputArray src1, InputArray src2,
                 OutputArray dst, InputArray mask=noArray());
void bitwise_or(InputArray src1, InputArray src2,
                 OutputArray dst, InputArray mask=noArray());
void bitwise_xor(InputArray src1, InputArray src2,
                 OutputArray dst, InputArray mask=noArray());
void bitwise_not(InputArray src1, OutputArray dst, InputArray mask=noArray());
```