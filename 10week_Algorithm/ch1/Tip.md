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
