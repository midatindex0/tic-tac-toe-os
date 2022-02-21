int verify(int filled[])
{
    if ((filled[0] == 1 && filled[1] == 1 && filled[2] == 1) || (filled[0] == 2 && filled[1] == 2 && filled[2] == 2))
        return 1;
    else if ((filled[3] == 1 && filled[4] == 1 && filled[5] == 1) || (filled[3] == 2 && filled[4] == 2 && filled[5] == 2))
        return 2;
    else if ((filled[6] == 1 && filled[7] == 1 && filled[8] == 1) || (filled[6] == 2 && filled[7] == 2 && filled[8] == 2))
        return 3;
    else if ((filled[0] == 1 && filled[3] == 1 && filled[6] == 1) || (filled[0] == 2 && filled[3] == 2 && filled[6] == 2))
        return 4;
    else if ((filled[1] == 1 && filled[4] == 1 && filled[7] == 1) || (filled[1] == 2 && filled[4] == 2 && filled[7] == 2))
        return 5;
    else if ((filled[2] == 1 && filled[5] == 1 && filled[8] == 1) || (filled[2] == 2 && filled[5] == 2 && filled[8] == 2))
        return 6;
    else if ((filled[0] == 1 && filled[4] == 1 && filled[8] == 1) || (filled[0] == 2 && filled[4] == 2 && filled[8] == 2))
        return 7;
    else if ((filled[2] == 1 && filled[4] == 1 && filled[6] == 1) || (filled[2] == 2 && filled[4] == 2 && filled[6] == 2))
        return 8;
    else if (filled[0] != 0 && filled[1] != 0 && filled[2] != 0 && filled[3] != 0 && filled[4] != 0 && filled[5] != 0 && filled[6] != 0 && filled[7] != 0 && filled[8] != 0)
        return -1;
    else
        return 0;
}