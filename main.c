/*
Name: ZALWANGO CHRISTINE 
Registration Number:25/U/BIE/01426/PE
*/

#include <stdio.h>

int main(void) {
    // Function to calculate grade and grade point
int calculate_grade(float score, float *grade_point) {
    if (score >= 80 && score <= 100) {
        *grade_point = 5;
        return 'A';
    } else if (score >= 70 && score <= 79) {
        *grade_point = 4;
        return 'B';
    } else if (score >= 60 && score <= 69) {
        *grade_point = 3;
        return 'C';
    } else if (score >= 50 && score <= 59) {
        *grade_point = 2;
        return 'D';
    } else if (score >= 0 && score <= 49) {
        *grade_point = 0;
        return 'F';
    } else {
        return -1; // Invalid score
    }
}

int main() {
    


    float scores[16];
    float grade_points[16];
    char grades[16];
    int credits[] = {4, 3, 3, 3, 3, 3, 2, 3, 4, 3, 3, 3, 3, 3, 3, 3};
    char *course_codes[] = {"TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108",
                           "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"};

    // Input scores
    for (int i = 0; i < 16; i++) {
        printf("Enter score for %s: ", course_codes[i]);
        scanf("%f", &scores[i]);
        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
        grades[i] = calculate_grade(scores[i], &grade_points[i]);
    }

    // Calculate GPA and CGPA
    float sem1_total_points = 0, sem2_total_points = 0;
    int sem1_total_credits = 0, sem2_total_credits = 0;

    for (int i = 0; i < 8; i++) {
        sem1_total_points += credits[i] * grade_points[i];
        sem1_total_credits += credits[i];
    }
    for (int i = 8; i < 16; i++) {
        sem2_total_points += credits[i] * grade_points[i];
        sem2_total_credits += credits[i];
    }

    float gpa_sem1 = sem1_total_points / sem1_total_credits;
    float gpa_sem2 = sem2_total_points / sem2_total_credits;
    float cgpa = (sem1_total_points + sem2_total_points) / (sem1_total_credits + sem2_total_credits);

    // Display report
    printf("\nAcademic Report:\n");
    for (int i = 0; i < 16; i++) {
        printf("%s: Score=%.1f, Grade=%c, GP=%.1f, Credits=%d\n", course_codes[i], scores[i], grades[i], grade_points[i], credits[i]);
    }

    printf("\nSemester I GPA: %.2f\n", gpa_sem1);
    printf("Semester II GPA: %.2f\n", gpa_sem2);
    printf("CGPA: %.2f\n", cgpa);

    // Classification
    char *classification;
    if (cgpa >= 4.40) classification = "First Class";
    else if (cgpa >= 3.60) classification = "Second Class Upper";
    else if (cgpa >= 2.80) classification = "Second Class Lower";
    else if (cgpa >= 2.00) classification = "Pass";
    else classification = "Fail";

    printf("Classification: %s\n", classification);
 return 0;
}
