#include <iostream>
#include <vector>

using Grid = std::vector<std::vector<int>>;

/// <summary>
/// Checks if the grid forms a magic square. Updates some variables that will be of good use later.
/// </summary>
/// <returns>The magic constant. -1 if it is not a magic square.</returns>
int MagicSquare(const Grid& grid, int size, std::vector<bool>& appearsInGrid, bool& outOfRange)
{
    int col = 0;
    int row = 0;
    int diagonal1 = 0;
    int diagonal2 = 0;

    for (int i = 0; i < size; i++)
    {
        col = row = 0;
        diagonal1 += grid[i][i];
        diagonal2 += grid[(size - 1) - i][i];

        for (int j = 0; j < size; j++)
        {
            row += grid[i][j];
            col += grid[j][i];

            int numb = grid[i][j];
            if (numb < 0 || numb > size * size) outOfRange = true;
            else appearsInGrid[numb - 1] = true;
        }

        // Not a magic square if they don't add to the same number
        if (row != col)
            return - 1;
    }

    // Every row and column add to the same number. Now checks for diagonals
    if (diagonal1 != diagonal2 || diagonal1 != row)
        return - 1;

    // Returns the sum of every row, column and main diagonal
    return row;
}

/// <summary>
/// Checks if the given magic square's side centers sum to the correct value.
/// </summary>
bool CheckSideCenters(const Grid& grid, int mc2)
{
    int size = grid.size();
    int center = size / 2;

    bool even = !(size % 2);
    if (even)
    {
        int sides = grid[0][center] + grid[size - 1][center] + grid[center][0] + grid[center][size - 1] +
            grid[0][center - 1] + grid[size - 1][center - 1] + grid[center - 1][0] + grid[center - 1][size - 1];
        
        return sides == 2 * mc2;
    }
    
    int sides = grid[0][center] + grid[size - 1][center] + grid[center][0] + grid[center][size - 1];

    return sides == mc2;
}

/// <summary>
/// Checks if the center of the given magic square adds up to the correct number.
/// </summary>
bool CheckCenters(const Grid& grid, int mc2)
{
    int size = grid.size();
    int center = size / 2;

    bool even = !(size % 2);

    if (even)
        return grid[center][center] + grid[center][center - 1] + grid[center - 1][center] + grid[center - 1][center - 1] == mc2;

    return grid[center][center] * 4 == mc2;
}

void Solve(const Grid& grid, int size)
{
    int cells = size * size;

    bool outOfRange = false;
    std::vector<bool> appearsInGrid(cells, false);
    int magicConstant = MagicSquare(grid, size, appearsInGrid, outOfRange);
    
    // If it is not a magic square, there is no way it is a diabolic or esoteric square.
    if (magicConstant == -1)
    {
        std::cout << "NO\n";
        return;
    }

    int MC2 = 4 * magicConstant / size;

    // If there is a number not in the [1, n^2 - 1] range, it is not esoteric.
    if(outOfRange)
    {
        std::cout << "DIABOLICO\n";
        return;
    }

    // In case there is a repeated digit.
    for (int i = 0; i < cells; i++)
    {
        if (!appearsInGrid[i])
        {
            std::cout << "DIABOLICO\n";
            return;
        }
    }

    // Check corners
    int corners = grid[0][0] + grid[size - 1][0] + grid[0][size - 1] + grid[size - 1][size - 1];
    if (corners != MC2)
    {
        std::cout << "DIABOLICO\n";
        return;
    }

    bool esoteric = CheckSideCenters(grid, MC2) && CheckCenters(grid, MC2);

    if(esoteric)
        std::cout << "ESOTERICO\n";
    else
        std::cout << "DIABOLICO\n";
}


int main()
{
    int size;
    std::cin >> size;

    while (size)
    {
        Grid grid(size, std::vector<int>(size));

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int n;
                std::cin >> n;

                grid[i][j] = n;
            }
        }

        Solve(grid, size);
        std::cin >> size;
    }
}