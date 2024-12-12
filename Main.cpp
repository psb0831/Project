#include "JobManager.h"
using namespace std;

int main() {
    //객체 생성
    JobManager manager;

    // 직업 데이터 추가
    manager.addJob(make_unique<SpecializedJob>("AI 전문가", "인공지능을 개발하고 연구하는 전문가.", 3, "IT"));
    manager.addJob(make_unique<SpecializedJob>("환경 기술자", "지속 가능한 환경 기술을 개발하는 직업.", 2, "환경"));
    manager.addJob(make_unique<SpecializedJob>("의료 데이터 분석가", "의료 데이터를 분석해 치료를 개선하는 직업.", 2, "의료"));
    manager.addJob(make_unique<SpecializedJob>("게임 디자이너", "창의적인 게임을 설계하고 개발하는 직업.", 1, "예술"));
    manager.addJob(make_unique<SpecializedJob>("로봇 공학자", "첨단 로봇 기술을 설계하고 개발하는 전문가.", 3, "IT"));
    manager.addJob(make_unique<SpecializedJob>("재생 에너지 전문가", "친환경 에너지를 연구하고 개발하는 직업.", 2, "환경"));

    try {
        int skillLevel;
        string field;

        cout << "=== 미래 직업 추천 시스템 ===\n";
        cout << "기술 수준을 입력하세요 (1: 초급, 2: 중급, 3: 고급): ";
        cin >> skillLevel;
        //사용자 입력받기
        if (skillLevel < 1 || skillLevel > 3) {
            throw invalid_argument("잘못된 기술 수준 입력입니다.");
        }

        cout << "관심 있는 분야를 입력하세요 (IT, 환경, 의료, 예술): ";
        cin >> field;

        cout << "\n추천 직업:\n";
        manager.recommendJobs(skillLevel, field);//직업 추천
    //예외처리
    } catch (const JobNotFoundException& e) {
        cout << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "알 수 없는 오류가 발생했습니다.\n";
    }

    return 0;
}