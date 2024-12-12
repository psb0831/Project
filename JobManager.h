#ifndef JOBMANAGER_H
#define JOBMANAGER_H

#include "SpecializedJob.h"
#include <memory>
#include <exception>

using namespace std; // std 네임스페이스를 사용

// 예외 클래스
class JobNotFoundException : public exception {
public:
    const char* what() const noexcept override {
        return "조건에 맞는 직업이 없습니다.";
    }
};

// JobManager 클래스: 직업 관리 및 추천 기능 제공
class JobManager {
private:
    vector<unique_ptr<Job>> jobs;

public:
    // 직업 추가
    void addJob(unique_ptr<Job> job) {
        jobs.push_back(move(job));
    }

    // 조건에 맞는 직업 추천
    void recommendJobs(int skillLevel, const string& field) const {
        bool found = false;
        for (const auto& job : jobs) {
            if (job->isSuitable(skillLevel, field)) {
                job->displayInfo();
                found = true;
            }
        }

        if (!found) {
            throw JobNotFoundException();
        }
    }
};

#endif