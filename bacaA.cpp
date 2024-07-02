int Cardinality(int z)
{
    int moc = 0;
    if ((z & (1 << 0)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 1)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 2)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 3)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 4)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 5)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 6)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 7)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 8)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 9)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 10)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 11)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 12)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 13)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 14)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 15)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 16)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 17)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 18)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 19)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 20)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 21)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 22)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 23)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 24)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 25)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 26)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 27)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 28)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 29)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 30)) != 0)
    {
        moc++;
    }
    if ((z & (1 << 31)) != 0)
    {
        moc++;
    }
    return moc;
}

bool Disjoint (int z1, int z2)
{
    if ((z1 & z2) == 0)
    {
        return 1;
    }
    return 0;
}

bool Conjunctive (int z1, int z2)
{
    if ((z1 & z2) == 0)
    {
        return 0;
    }
    return 1;
}

void Emplace (char* ciag, int* z1) {
    static int zerowanie = 0;

    if (zerowanie == 0) {
        *z1 = 0;
        zerowanie = 1;
    }

    if (*ciag == '\0') {
        zerowanie = 0;
        return;
    }
    int ciagDziesietnie = 0;
    if (*ciag == ' ') {
        return Emplace(ciag + 1, z1);
    }
    if ((*ciag != ' ') && (*ciag != '\0')) {
        int pierwszy = (*ciag) - '0';
        int drugi = (*(ciag + 1)) - '0';
        int trzeci = (*(ciag + 2)) - '0';
        int czwarty = (*(ciag + 3)) - '0';
        int piaty = (*(ciag + 4)) - '0';
        ciagDziesietnie = (pierwszy * 16) + (drugi * 8) + (trzeci * 4) + (czwarty * 2) + (piaty);
    }
    int doWstawienia = (1 << ciagDziesietnie);
    *z1 = (*z1 | doWstawienia);
    return Emplace(ciag + 5, z1);

}

bool Emptiness (int z1)
{
    if (z1 == 0)
    {
        return 1;
    }
    return 0;
}

bool Nonempty (int z1)
{
    if (z1 != 0)
    {
        return 1;
    }
    return 0;
}

void Erase  (char *ciag, int *z1)
{
    if (*ciag == '\0')
    {
        return;
    }
    int ciagDziesietnie = 0;
    if (*ciag == ' ')
    {
        return Erase(ciag + 1, z1);
    }
    if ((*ciag != ' ') && (*ciag != '\0'))
    {
        int pierwszy = (*ciag) - '0';
        int drugi = (*(ciag + 1)) - '0';
        int trzeci = (*(ciag + 2)) - '0';
        int czwarty = (*(ciag + 3)) - '0';
        int piaty = (*(ciag + 4)) - '0';
        ciagDziesietnie = (pierwszy * 16) + (drugi * 8) + (trzeci * 4) + (czwarty * 2) + (piaty);
    }
    int doWstawienia = (1 << ciagDziesietnie);
    *z1 = (doWstawienia ^ *z1) & *z1;
    return Erase(ciag + 5, z1);
}

bool Inclusion (int z1, int z2)
{
    if (z2 == (z1 | z2))
    {
        return 1;
    }
    return 0;
}

bool Equality (int z1, int z2)
{
    if (z1 == z2)
    {
        return 1;
    }
    return 0;
}

void Insert (char* ciag, int* z1)
{
    if (*ciag == '\0')
    {
        return;
    }
    int ciagDziesietnie = 0;
    if (*ciag == ' ')
    {
        return Insert(ciag + 1, z1);
    }
    if ((*ciag != ' ') && (*ciag != '\0'))
    {
        int pierwszy = (*ciag) - '0';
        int drugi = (*(ciag + 1)) - '0';
        int trzeci = (*(ciag + 2)) - '0';
        int czwarty = (*(ciag + 3)) - '0';
        int piaty = (*(ciag + 4)) - '0';
        ciagDziesietnie = (pierwszy * 16) + (drugi * 8) + (trzeci * 4) + (czwarty * 2) + (piaty);
    }
    int doWstawienia = (1 << ciagDziesietnie);
    *z1 = (*z1 | doWstawienia);
    return Insert(ciag + 5, z1);
}

bool Member ( char* ciag, int z1)
{
    int ciagDziesietnie = 0;
    if (*ciag == ' ')
    {
        return Member(ciag + 1, z1);
    }
    else
    {
        int pierwszy = (*ciag) - '0';
        int drugi = (*(ciag + 1)) - '0';
        int trzeci = (*(ciag + 2)) - '0';
        int czwarty = (*(ciag + 3)) - '0';
        int piaty = (*(ciag + 4)) - '0';
        ciagDziesietnie = (pierwszy * 16) + (drugi * 8) + (trzeci * 4) + (czwarty * 2) + (piaty);
    }
    int porownanie = (1 << ciagDziesietnie);
    int porownanie2 = (z1 & porownanie);
    if (porownanie2)
    {
        return 1;
    }
    return 0;
}

void Union (int z1, int z2, int *z3)
{
    *z3 = (z1 | z2);
}

void Intersection (int z1, int z2, int *z3)
{
    *z3 = (z1 & z2);
}

void Symmetric (int z1, int z2, int *z3)
{
    *z3 = (z1 ^ z2);
}

void Difference (int z1, int z2, int *z3)
{
    *z3 = (z1 & (~z2));
}

void Complement (int z1, int *z2)
{
    *z2 = ~z1;
}

void Print ( int z1, char* ciag)
{
    int i = 0;
    if (z1 == 0)
    {
        *ciag = 'e';
        *(ciag + 1) = 'm';
        *(ciag + 2) = 'p';
        *(ciag + 3) = 't';
        *(ciag + 4) = 'y';
        *(ciag + 5) = '\0';
        return;
    }
    else
    {
        if ((z1  & (1 << 31)) != 0)
        {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i = i + 6;
        }
        if ((z1  & (1 << 30)) != 0)
        {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i = i + 6;

        }
        if ((z1  & (1 << 29)) != 0)
        {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;


        }
        if ((z1 & (1 << 28)) != 0)
        {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 27)) != 0)
        {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 26)) != 0)
        {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 25)) != 0)
        {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 24)) != 0)
        {
            *(ciag +i) = '1';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 23)) != 0) {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 22)) != 0) {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 21)) != 0) {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 20)) != 0) {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 19)) != 0) {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 18)) != 0) {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 17)) != 0) {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 16)) != 0) {
            *(ciag + i) = '1';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 15)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 14)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 13)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 12)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 11)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 10)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 9)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 8)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '1';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 7)) != 0) {
            *(ciag + i)= '0';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 6)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 5)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 4)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '1';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 3)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 2)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '1';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 1)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '1';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        if ((z1 & (1 << 0)) != 0) {
            *(ciag + i) = '0';
            *(ciag + 1 + i) = '0';
            *(ciag + 2 + i) = '0';
            *(ciag + 3 + i) = '0';
            *(ciag + 4 + i) = '0';
            *(ciag + 5 + i) = ' ';
            i += 6;
        }
        *(ciag + i - 6 + 5) = '\0';
    }
}

bool LessThen (int z1, int z2)
{
    int moc1 = Cardinality(z1);
    int moc2 = Cardinality(z2);
    if (moc1 == moc2)
    {
        return z1 < z2;
    }
    else
    {
        return moc1 < moc2;
    }

}

bool LessEqual (int z1, int z2)
{
    int moc1 = Cardinality(z1);
    int moc2 = Cardinality(z2);
    if (moc1 == moc2)
    {
        return z1 <= z2;
    }
    else
    {
        return moc1 <= moc2;
    }
}

bool GreatEqual (int z1, int z2)
{
    return (!LessThen(z1, z2));
}

bool GreatThen (int z1, int z2)
{
    return (!LessEqual(z1, z2));
}

