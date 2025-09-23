    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = multiply_Matrices(result, A);
        }
        A = multiply_Matrices(A, A);
        power /= 2;
    }

    return result;
}