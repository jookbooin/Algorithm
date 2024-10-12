#include <iostream>
#include <queue>
#include <functional>    // greater
using namespace std;
 
struct Student {
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {}    // 생성자 정의
};

// pq - id 큰것 
struct cmp1 {
    bool operator()(Student a, Student b) {
        return a.id < b.id;
    }
};

// pq - math 오름차순
struct cmp2 {
    bool operator()(Student& a, Student& b) const {
        return a.math > b.math;
    }
};

// pq - eng 내림차순 
struct cmp3 {
    bool operator()(Student& a, Student& b) const {
        return a.eng < b.eng;
    }
};
 
int main() {
    
    cout << "1. id 내림차순" << endl;
    priority_queue<Student, vector<Student>, cmp1> pq1;  
 
    pq1.push(Student(3, 100, 50));
    pq1.push(Student(1, 60, 50));
    pq1.push(Student(2, 80, 50));
    pq1.push(Student(4, 90, 50));
    pq1.push(Student(5, 70, 40));
    
    while (!pq1.empty()) {
        Student ts = pq1.top(); pq1.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }

    cout << endl;
    cout << "2. math 오름차순" << endl;  
    priority_queue<Student, vector<Student>, cmp2> pq2;  
 
    pq2.push(Student(3, 100, 50));
    pq2.push(Student(1, 60, 50));
    pq2.push(Student(2, 80, 50));
    pq2.push(Student(4, 90, 50));
    pq2.push(Student(5, 70, 40));
    
    while (!pq2.empty()) {
        Student ts = pq2.top(); pq2.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }

    cout << endl;
    cout << "3. eng 내림차순" << endl;  
    priority_queue<Student, vector<Student>, cmp3> pq3;  
 
    pq3.push(Student(3, 100, 50));
    pq3.push(Student(1, 60, 50));
    pq3.push(Student(2, 80, 50));
    pq3.push(Student(4, 90, 50));
    pq3.push(Student(5, 70, 40));
    
    while (!pq3.empty()) {
        Student ts = pq3.top(); pq3.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }
 
 
    return 0;
}