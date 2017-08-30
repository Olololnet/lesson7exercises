#include <iostream>
#include "cpoint.h"

struct CTeam
{
    char   m_pTeamName[20];
    double m_dScore;
};

struct CHockeyTeams
{
    CTeam* m_pTeams;
    int    m_iTeamsCount;
};

void InsertTeamsData(CHockeyTeams* pHocheyTeams)
{
    std::cout << "Now enter data for all teams (for " << pHocheyTeams->m_iTeamsCount << " teams)" << std::endl;
    for (int i = 0; i < pHocheyTeams->m_iTeamsCount; i++)
    {
        std::cout << "Now enter data for team #" << (i + 1) << " : name, score" << std::endl;
        std::cin >> pHocheyTeams->m_pTeams[i].m_pTeamName;
        std::cin >> pHocheyTeams->m_pTeams[i].m_dScore;
    }
}

double GetBestTeamScore(CHockeyTeams* pHocheyTeams)
{
    int iBestTeamIndex = 0;

    for (int i = 1; i < pHocheyTeams->m_iTeamsCount; i++)
    {
        if (pHocheyTeams->m_pTeams[iBestTeamIndex].m_dScore < pHocheyTeams->m_pTeams[i].m_dScore)
            iBestTeamIndex = i;
    }

    return pHocheyTeams->m_pTeams[iBestTeamIndex].m_dScore;
}

void FindFilteredTeam(CHockeyTeams* pHocheyTeams, const double& iBestScore)
{
    double dScoreHalf = iBestScore/2;

    int iCurrentFilteredMinIndex = 0;
    bool bIsMinimumNotSet = true;

    for (int i = 0; i < pHocheyTeams->m_iTeamsCount; i++)
    {
        if (pHocheyTeams->m_pTeams[i].m_dScore < dScoreHalf + 1e-2)
            continue;
        else
        {
            if (bIsMinimumNotSet)
            {
                iCurrentFilteredMinIndex = i;
                bIsMinimumNotSet = false;
            }
            else
            {
                if (pHocheyTeams->m_pTeams[iCurrentFilteredMinIndex].m_dScore > pHocheyTeams->m_pTeams[i].m_dScore)
                    iCurrentFilteredMinIndex = i;
            }
        }
    }

    std::cout << "Filtered team: " << pHocheyTeams->m_pTeams[iCurrentFilteredMinIndex].m_pTeamName
              << " with score: " << pHocheyTeams->m_pTeams[iCurrentFilteredMinIndex].m_dScore << std::endl;
}

void ExerciseOnLesson2()
{
    // ExerciseOnLesson2: Среди всех этих команд найти минимальную,
    // у которой количество очков больше половины очков победителя

    int iTeamCount = 0;
    std::cout << "Enter amount of teams (to find team with minimum score higher"
              << " than half score of best team)" << std::endl;
    std::cin >> iTeamCount;

    if (iTeamCount <= 0)
    {
        std::cout << "Amount of teams must be > 0" << std::endl;
        return;
    }

    CHockeyTeams* pHocheyTeams = new CHockeyTeams;
    pHocheyTeams->m_iTeamsCount = iTeamCount;
    pHocheyTeams->m_pTeams = new CTeam[iTeamCount];

    InsertTeamsData(pHocheyTeams);

    double iBestTeamScore = GetBestTeamScore(pHocheyTeams);
    FindFilteredTeam(pHocheyTeams, iBestTeamScore);

    delete[] pHocheyTeams->m_pTeams;
    delete   pHocheyTeams;
}

void FindBestTeam(CHockeyTeams* pHocheyTeams)
{
    int iBestTeamIndex = 0;

    for (int i = 1; i < pHocheyTeams->m_iTeamsCount; i++)
    {
        if (pHocheyTeams->m_pTeams[iBestTeamIndex].m_dScore < pHocheyTeams->m_pTeams[i].m_dScore)
            iBestTeamIndex = i;
    }

    std::cout << "Best team is " << pHocheyTeams->m_pTeams[iBestTeamIndex].m_pTeamName
              << ", score: " << pHocheyTeams->m_pTeams[iBestTeamIndex].m_dScore << std::endl;
}

void FindWeakTeam(CHockeyTeams* pHocheyTeams)
{
    int iWeakTeamIndex = 0;

    for (int i = 1; i < pHocheyTeams->m_iTeamsCount; i++)
    {
        if (pHocheyTeams->m_pTeams[iWeakTeamIndex].m_dScore > pHocheyTeams->m_pTeams[i].m_dScore)
            iWeakTeamIndex = i;
    }

    std::cout << "Weak team is " << pHocheyTeams->m_pTeams[iWeakTeamIndex].m_pTeamName
              << ", score: " << pHocheyTeams->m_pTeams[iWeakTeamIndex].m_dScore << std::endl;
}

void ExerciseOnLesson1()
{
    // ExerciseOnLesson1: Заполните массив данными о командах по хоккею (название команды
    // и количество очков). Найти команду с максимальным и минимальным числом очков

    int iTeamCount = 0;
    std::cout << "Enter amount of teams (to find best and weak teams)" << std::endl;
    std::cin >> iTeamCount;

    if (iTeamCount <= 0)
    {
        std::cout << "Amount of teams must be > 0" << std::endl;
        return;
    }

    CHockeyTeams* pHocheyTeams = new CHockeyTeams;
    pHocheyTeams->m_iTeamsCount = iTeamCount;
    pHocheyTeams->m_pTeams = new CTeam[iTeamCount];

    InsertTeamsData(pHocheyTeams);
    FindWeakTeam(pHocheyTeams);
    FindBestTeam(pHocheyTeams);

    delete[] pHocheyTeams->m_pTeams;
    delete   pHocheyTeams;
}

void ExerciseAllInOne()
{
    // 1: реализовать класс точки с методом, вычисляющий расстояние между двумя точками
    // (distance)
    // 2: написать метод, который сравнивает точки (возвращает bool)
    // 3: написать метод сложения точек

    CPoint Point1(0.2, 1.5);
    CPoint Point2(2.5, 3.1);

    double dDistance = Point1.GetDistance(Point2);
    std::cout << "Distance between point1 and point2: " << dDistance << std::endl << std::endl;

    bool IsSecondFarther = Point1.IsPointFartherThanSecond(Point2);

    if (IsSecondFarther)
        std::cout << "Point1 is farther than point2" << std::endl << std::endl;
    else
        std::cout << "Point2 is farther than point1" << std::endl << std::endl;

    Point1.SumCoordsWithOtherPoint(Point2);

    Point1.Print();
}

int main()
{
//    ExerciseOnLesson1();
//    ExerciseOnLesson2();
//    ExerciseAllInOne();

    return 0;
}

