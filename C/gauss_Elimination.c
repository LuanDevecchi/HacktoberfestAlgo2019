#include <stdio.h>
#include <math.h>

void elimination_gauss();

int main()
{
    int i, j, n_row, m_column;

    scanf("%d", &n_row);

    scanf("%d", &m_column);

    double matrix[n_row][m_column];

    double gaussiano_vetor[m_column];

    for ( i = 0; i < n_row; i++)
    {
        for ( j = 0; j < m_column; j++)
        {
            scanf("%lf",&matrix[i][j]);
        }
    }

    elimination_gauss(n_row, m_column, matrix, gaussiano_vetor);


    printf("Resolution:\n");
    for ( i = 0; i < m_column - 1; i++)
    {
        printf("%9.0lf ,",gaussiano_vetor[i]);
    }
    

    return 0;
}

void elimination_gauss(int n_rows, int m_columns, double matrix_elimination[n_rows][m_columns], double vetor_gaussiano[m_columns - 1])
{ 
    double coeficiente_vetor_gaussiano = 0;

    double temporario_aux;

    int i, j, k;

    for(i = 0; i < n_rows - 1; i++)
    {
        for ( k = i + 1; k < n_rows; k++)
        {
            if(fabs(matrix_elimination[i][i]) < fabs(matrix_elimination[k][i]))
            {
                for ( j = 0; j < m_columns; j++)
                {
                    temporario_aux = matrix_elimination[i][j];

                    matrix_elimination[i][j] = matrix_elimination[k][j];

                    matrix_elimination[k][j] = temporario_aux;

                }
            }
        }

        for ( k = i + 1; k < n_rows; k++)
        {
            coeficiente_vetor_gaussiano = (matrix_elimination[k][i] / matrix_elimination[i][i]);

            for ( j = 0; j < m_columns; j++)
            {
                matrix_elimination[k][j] = matrix_elimination[k][j] - coeficiente_vetor_gaussiano*matrix_elimination[i][j];
            }
        }
    }
    for ( i = n_rows - 1; i >= 0; i--)
    {
        vetor_gaussiano[i] = matrix_elimination[i][m_columns - 1];

        for ( j = i + 1; j < m_columns - 1; j++)
        {
            vetor_gaussiano[i] = (vetor_gaussiano[i] - matrix_elimination[i][j]*vetor_gaussiano[j]);
        }
    
        vetor_gaussiano[i] = vetor_gaussiano[i] / matrix_elimination[i][i];  
    }
    
    for ( i = 0; i < n_rows; i++)
    {
        for ( j = 0; j < m_columns; j++)
        {
            printf("%9.2lf", matrix_elimination[i][j]);
        }
        printf("\n\n");
    }
}
