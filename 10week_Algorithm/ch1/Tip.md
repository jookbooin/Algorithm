#### 10988

* `cin >> s` 로 입력받은 문자열 (string) s[0], s[1] .. 
* reverse( start , end ) 로 뒤집기 가능 
  * 단 원본 문자열도 바뀐다.
  * reverse (start + 3, end) 처럼 범위를 지정할 수 있음
* c++ 에서는 `연산자 오버로딩`으로 인해 `==` 로 문자열(값)을 비교할 수 있다.


#### 1159
* `개수 세기` → `map` + `배열`
* string[0] = char 형이다
* 아스키 코드 
  * int : arr[s[0] - `a`]
  * char : int + `a`


#### 11655
* 아스키 코드 대문자 (`65 ~ 90`), 소문자 (`97 ~ 122`)
* `cin`: 개행문자 직전 까지 입력받음 
  `getline` : 전체 라인 입력받을때 사용
  
# 1-J 9375

## 1. 경우의 수 
경우의 수는 수가 커질 수 있음. `long long`으로 선언하는 것이 좋다

## 2. map

* auto 

``` cpp
for(auto it : map)
// map.first = key 
// map.second = value
```

* map iterator 순회
``` cpp
for(auto it = map.begin(); it!=map.end(); it++)
```

# 1-K 1213
## 알파벳 배열
``` cpp
int alpha[26]; 

cin >> input;

for (char c : input) {
    alpha[c - 'A']++;
}
```

## 비트마스킹으로 홀수/짝수 구별
``` cpp
if (alpha[i] & 1) { // 홀수

}else {             // 짝수
}
```

# 1-L 1213

## 조합 nCr
* r <=3 : for 문
* r > 3 : 재귀 사용

# 1-M 3986
* 짝짓기, 폭발 나오면 → STACK 의심
* stack.top() 쓰기전 size 체크 해야함


# 1-N 1629

## 분할 정복 : O(logN)
B가 20억이 넘어 for문을 사용하면  `O(N)`의 시간 복잡도를 가진다.

`분할 정복`을 이용해서 더 작은 문제로 나누어서 계산한다. 
나누어서 계산하기 때문에 `O(logN)` 시간 복잡도를 가지게 된다.

* p(8) = p(4) * p(4) 
* p(4) = p(2) * p(2)
* p(2) = p(1) * p(1)

* p(7) = p(3) * p(3 + `1`)
* p(3) = p(1 + `1`) * p(1)

``` cpp
int go (int in, int num){           // 7
  if (num == 1) return in % c;
  
  ll result = go(in, num / 2);      // 3 
  result = (result * result) % c ;  // 3 + 3 
  if(num % 2 == 1) 
    result = result * in %c         // 3 + 1 

  return result;
}

```

# 1-O 4375

## 모듈러 연산 
```
a % n = ( a % n ) % n
= ( 0 ~ n-1 ) % n
= ( 0 ~ n-1 )

( a * b ) % n
= ( a % n * b ) % n 
= ( a % n % n * b % n) % n = ( a % n * b % n ) % n
```
 
따라서 다음과 같이 쓸 수 있게 된다..
( a * b + c ) % n = ( `a % n` * b + c ) % n



