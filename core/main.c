/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** main
*/

char *main1()
{
    char *file = "main";
    printf("%s", file);
    return (file);
}

int main(int argc, char **argv)
{
    argv[1] = main1();
}