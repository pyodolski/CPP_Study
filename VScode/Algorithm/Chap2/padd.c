void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
    float coefficient;
    *startd = avail; // 결과 다항식의 시작 인덱스 저장 (avail은 비어 있는 인덱스)

    // a와 b의 항들을 비교하면서 처리
    while (starta <= finisha && startb <= finishb)
    {
        switch (COMPARE(terms[starta].expon, terms[startb].expon))
        {
        case -1: // b의 지수가 더 크면 b의 항을 추가하고 startb 증가
            attach(terms[startb].coef, terms[startb].expon);
            startb++;
            break;

        case 0: // 지수가 같을 때 계수를 더해주고, 두 항을 모두 처리
            coefficient = terms[starta].coef + terms[startb].coef;
            if (coefficient)
            { // 계수가 0이 아니면 항을 추가
                attach(coefficient, terms[starta].expon);
            }
            starta++;
            startb++;
            break;

        case 1: // a의 지수가 더 크면 a의 항을 추가하고 starta 증가
            attach(terms[starta].coef, terms[starta].expon);
            starta++;
            break;
        }
    }

    // a의 남은 항들을 결과 다항식에 추가
    for (; starta <= finisha; starta++)
    {
        attach(terms[starta].coef, terms[starta].expon);
    }

    // b의 남은 항들을 결과 다항식에 추가
    for (; startb <= finishb; startb++)
    {
        attach(terms[startb].coef, terms[startb].expon);
    }

    *finishd = avail - 1; // 결과 다항식의 마지막 인덱스 저장
}

// O(n+m)