#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Subject {
private:
    int score;
protected:
    int max_score;
    string subject_name;
public:
    Subject(string name, int max_score) {
        this->subject_name = name;
        this->max_score = max_score;
    }
    string getSubjectName() {
        return this->subject_name;
    }
    void setScore(int score) {
        this->score = score;
    }
    int getMaxScore() {
        return this->max_score;
    }
    int getScore() {
        return this->score;
    }
};

class Korean : public Subject {
public:
    Korean() : Subject::Subject("국어", 100) {}
};

class Math : public Subject {
public:
    Math() : Subject::Subject("수학", 100) {}
};

class History : public Subject {
public:
    History() : Subject::Subject("역사", 50) {}
};

class Student {
private:
    string name;
    int sum;
public:
    vector<Subject> subjects;
    Student(string name) {
        this->name = name;
        Korean korean;
        Math math;
        History history;
        subjects.push_back(korean);
        subjects.push_back(math);
        subjects.push_back(history);
        this->sum = 0;
    }
    void print() {
        cout << "===== Student " << this->name << " =====\n";
        for (auto elem : subjects) {
            cout << elem.getSubjectName() << ": " << elem.getScore() << " / " << elem.getMaxScore() << '\n';
            this->sum += elem.getScore();
        }
        cout << "Sum of scores: " << this->sum << "\n================\n";
    }
    int getSum() {
        return this->sum;
    }
    string getName() {
        return this->name;
    }
};

bool compare(Student a, Student b) {
    return a.getSum() >= b.getSum();
}

void printRank(vector<Student> students) {
    sort(students.begin(), students.end(), compare);
    for (int i = 0; i < students.size(); i++) {
        cout << "Rank " << i + 1 << ": " << students[i].getName() << " (" << students[i].getSum() << "/250)\n";
    }
}

int main() {
    // 총 학생의 수 입력
    int n;
    cout << "How many students:";
    cin >> n;
    
    vector<Student> students;
    // 학생의 성적 입력
    for (int i = 0; i < n; i++) {
        string name;
        cout << "Name of student: ";
        cin >> name;

        Student student(name);

        for (Subject& subject: student.subjects) {
            int score;
            cout << "Score of " << subject.getSubjectName() << ": ";
            cin >> score;

            try {
                subject.setScore(score);
            } catch (out_of_range& e) {
                cout << e.what();
                return 0;
            }
        }
        student.print();
        students.push_back(student);
    }
    // 학생들의 순위 출력
    cout << "====== Rank" << endl;
    printRank(students);
    return 0;
}
