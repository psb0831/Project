#ifndef SPECIALIZEDJOB_H
#define SPECIALIZEDJOB_H

#include "Job.h"

// SpecializedJob 클래스: 특정 기술 수준과 분야를 가진 직업
class SpecializedJob : public Job {
private://추가 멤버 변수, 생성자
    int requiredSkillLevel;
    string field;
    
public:
    SpecializedJob(const string& name, const string& description, int skillLevel, const string& field)
        : Job(name, description), requiredSkillLevel(skillLevel), field(field) {}
    //직업 정보 출력
    void displayInfo() const override {
        cout << "- " << name << ": " << description
             << " (필요 기술 수준: " << requiredSkillLevel
             << ", 분야: " << field << ")\n";
    }

    bool isSuitable(int skillLevel, const string& inputField) const override {
        return (skillLevel >= requiredSkillLevel && field == inputField);
    }
};

#endif