#include <stdio.h>
//수학관련 라이브러리 가져오기
#include <math.h>

void menu();
//일일 카페인 최대량 계산
float caf_per_day(float weight);
//일일 아메리카노 치사량 계산
float americano_lethal_dose(float weight);
//체질량지수 계산
float bmi(float weight, float height);
//비만도 결과 출력
void bmiresult(float weight, float height);
//물 치사량
float water_lethal_dose(float weight);

//main 함수
int main(void) {

    //변수선언
    float height = 0;
    float weight = 0;
    int choice = 0;

    printf("당신의 건강 계산기\n");

    //신체 사항 입력
    printf("당신의 몸무게를 입력하세요");
    scanf("%f", &weight);
    printf("당신의 키를 입력하세요");
    scanf("%f", &height);

    //무한 루프
    while (1) {
        //메뉴판 호출
        menu();

        printf("당신이 알고자 하는 정보를 고르시오.(0입력시 종료)");
        scanf("%d", &choice);

        //무한 루프 반복문 탈출 조건
        if(choice==0)break;

        //choice 값에 따라 해당 케이스로 이동
        switch (choice) {
            
            case 1:
                printf("당신의 일일 카페인 최대치는 %.1f입니다.\n",caf_per_day(weight));
                break;
            case 2:
                printf("당신의 일일 아메리카노 치사량은 %.1f mL입니다.\n",americano_lethal_dose(weight));
                break;
            case 3:
                printf("당신의 체질량지수는 %.1f입니다\n",bmi(weight,height));
                break;
            case 4:
                bmiresult(weight, height);
                break;
            case 5:
                printf("당신이 하루에 %.1fL이상 마시면 물중독으로 사망할 위험이 큽니다.\n",water_lethal_dose(weight));
                break;

        }
    }
    return 0;
}

void menu() {
    printf("\n");
    printf("1.일일 카페인 최대치\n");
    printf("2.일일 아메리카노 치사량\n");
    printf("3.체질량 지수\n");
    printf("4.bmi에 따른 당신의 등급\n");
    printf("5.일일 물 흡수 치사량 계산\n");
}

//일일 카페인량
float caf_per_day(float weight) {
    int day_caf = 0;

    day_caf = weight * 2.5;

    return day_caf;
}

//일일 아메리카노 치사량
float americano_lethal_dose(float weight) {
    float lethal_dose = 0;
    lethal_dose = weight * 362;
    return lethal_dose;
}

//체지방지수
float bmi(float weight, float height) {
    float bmi_1 = 0;
    //bmi계산 : 몸무게/키^2
    //pow함수 - 제곱화
    bmi_1 = (weight / pow(height/100, 2));
    return bmi_1;
}

//bmi에 따른 등급
void bmiresult(float weight, float height){
    //bmi 함수 호출 및 변수에 그 값 저장
    float bmi_1 = bmi(weight, height);
    if(bmi_1>=35){
        printf("당신은 3단계 비만 입니다.\n");
    }
    else if(bmi_1>=30){
        printf("당신은 2단계 비만 입니다.\n");
    }
    else if(bmi_1>=25){
        printf("당신은 1단계 비만 입니다.\n");
    }
    else if(bmi_1>=23){
        printf("당신은 비만 전단계입니다.\n");
    }
    else if(bmi_1>=18.5){
        printf("당신은 정상입니다.\n");
    }
    else{
        printf("당신은 저체중입니다.\n");
    }

}

//물중독 사망률
float water_lethal_dose(float weight){
    float water_ld = 0.0;

    water_ld = weight*0.09;

    return water_ld;
}