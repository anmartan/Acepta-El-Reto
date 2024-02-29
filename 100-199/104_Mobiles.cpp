#include <iostream>
#include <vector>

int calculateStability(std::vector<int>& mobile)
{
    if (mobile[0] == 0)
    {
        std::vector<int> leftArm(4);
        std::cin >> leftArm[0] >> leftArm[1] >> leftArm[2] >> leftArm[3];
        mobile[0] = calculateStability(leftArm);
    }

    if (mobile[2] == 0)
    {
        std::vector<int> rightArm(4);
        std::cin >> rightArm[0] >> rightArm[1] >> rightArm[2] >> rightArm[3];
        mobile[2] = calculateStability(rightArm);
    }

    if (mobile[0] == -1 || mobile[2] == -1) return -1;

    if (mobile[0] * mobile[1] == mobile[2] * mobile[3])
        return mobile[0] + mobile[2];

    return -1;
}

void solve(std::vector<int>& mobile)
{
    if (calculateStability(mobile) == -1)
        std::cout << "NO\n";
    else std::cout << "SI\n";
}


int main()
{
    std::vector<int> mobile(4);

    while (true)
    {
        std::cin >> mobile[0] >> mobile[1] >> mobile[2] >> mobile[3];
        if (mobile[0] == 0 && mobile[1] == 0 && mobile[2] == 0 && mobile[3] == 0) break;

        solve(mobile);
    }

    return 0;
}