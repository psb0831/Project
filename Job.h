/* 
컴퓨터 프로그래밍 및 실습 평가과제
학과: 수학과
학번: 202001472
이름: 박승범
과제 주제: 미래 직업 추천 시스템
*/

#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <string>
#include <vector>

using namespace std; // std 네임스페이스를 사용

// 추상 클래스 Job
class Job {
protected:
    string name;//직업이름
    string description;//직업 설명

public://생성자 name과 description을 초기화
    Job(const string& name, const string& description)
        : name(name), description(description) {}

    virtual void displayInfo() const = 0; // 순수 가상 함수
    virtual bool isSuitable(int skillLevel, const string& field) const = 0;
    virtual ~Job() {}//가상 소멸자
};

#endif