#include <ctype.h>
#include "libft.h"


int main()
{
printf("----------------------------------------------------------------------------\n");	
printf("****************PRGRAMME DE CORRECTION LIBFT 42 By yonieva****************\n") ;
printf("                Veuillez appuyer sur 'ENTER' pour commencer                \n");
printf("----------------------------------------------------------------------------\n");	
getchar();
printf("----------------------------------------------------------------------------\n");	
printf("FONCTION ft_atoi(const char *str)\n") ;

    const   char *str = "76789abc67-7";
	
		printf("le vrai atoi pour l exemple '76789abc67-7': %d\n",	atoi(str));
		printf("ma fonction : %d\n", ft_atoi(str));
printf("----------------------------------------------------------------------------\n");	
printf("FONCTION size_t	ft_strlen(const char *str) pour l exemple 'coucou ' et 'anticonstitutionnellement'\n");

const char *s1 = "coucou";
 const char *s2 = "anticonstitutionnellement";

printf("ma fonction %ld, la vrai fonction %ld\n", ft_strlen(s1), strlen(s1));
printf("ma fonction %ld, la vrai fonction %ld\n", ft_strlen(s2), strlen(s2));
printf("----------------------------------------------------------------------------\n");	
/*printf("FONCTION size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)\n");
	const char	*str15 = "Salut";
	char	*str25 = "Il fait beau dans mon coeur";

printf("Ma fonction avec src < dest : %ld\n", ft_strlcpy(str25, str15, 5));
printf("Pas reussi a comparer avec la vrai fonction");
printf("----------------------------------------------------------------------------\n");*/
printf("FONCTION size_t	ft_strlcat(char *dest, const char *src, size_t destsize)\n");
	char	*str12;
	char	*str22;

	str12 = "Salut";
	str22 = "Ca va ?";
	printf("Ma fonction : %ld\n", ft_strlcat(str22, str12, 5));
	printf("Pas reussi a comparer avec la vrai\n");	
printf("----------------------------------------------------------------------------\n");
printf("FONCTION int ft_isalpha(int c)\n");
 char	a = 'A';
 char	b = 'a';
 char   c = '8';

printf ("Ma fonction pour l exemple 'A', 'a' et '8':\n %d, %d, %d\n", ft_isalpha(a), ft_isalpha(b), ft_isalpha(c));
printf ("Le vrai isalpha pour l exemple 'A', 'a' et '8':\n %d, %d, %d\n", isalpha(a), isalpha(b), isalpha(c));
printf("----------------------------------------------------------------------------\n");	
printf("FONCTION int ft_isdigit(int c)\n");
char	a1 = 'A';
 char	b1 = 'a';
 char   c1 = '8';

printf ("Ma fonction pour l exemple 'A', 'a' et '8': %d, %d, %d\n", ft_isdigit(a1), ft_isdigit(b1), ft_isdigit(c1) );
printf ("Le vrai isalpha pour l exemple 'A', 'a' et '8': %d, %d, %d\n", isdigit(a1), isdigit(b1), isdigit(c1));
printf("----------------------------------------------------------------------------\n");	
printf("FONCTION int ft_isalnum(int c)\n");
 char	a2 = 'A';
 char	b2 = 'a';
 char   c2 = '8';

printf ("Ma fonction pour l exemple 'A', 'a' et '8': %d, %d, %d\n", ft_isalnum(a2), ft_isalnum(b2), ft_isalnum(c2));
printf ("Le vrai isalpha pour l exemple 'A', 'a' et '8': %d, %d, %d\n", isalnum(a2), isalnum(b2), isalnum(c2));
printf("----------------------------------------------------------------------------\n");	
printf("FONCTION int ft_isascii(int c)\n");

    int	a3 = 9;
	int b3 = 'A';
	char c3= '-';

printf ("Ma fonction pour l exemple '9', 'A' et '-': %d, %d, %d\n", ft_isascii(a3), ft_isascii(b3), ft_isascii(c3));
printf ("Le vrai isascii pour l exemple 'A', 'a' et '-': %d, %d, %d\n", isascii(a3), isascii(b3), isascii(c3));
printf("----------------------------------------------------------------------------\n");	
printf("FONCTION int ft_isprint(int c)\n");
char	a4 = 'A';
 char	b4 = '9';
 char   c4 = ' ';

printf ("Ma fonction pour l exemple 'A', '9' et ' ': %d, %d, %d\n", ft_isprint(a4), ft_isprint(b4), ft_isprint(c4));
printf ("Le vrai isprint pour l exemple 'A', '9' et ' ': %d, %d, %d\n", isalnum(a4), isalnum(b4), isalnum(c4));
printf("----------------------------------------------------------------------------\n");	
printf("FONCTION int ft_tolower(int c)\n");
    int	a5 = 'A';
	int b5= 'a';
	int c5 = '5';

printf ("Ma fonction pour l exemple A, a et 5 : %c, %c et %c\n",ft_tolower(a5), ft_tolower(b5), ft_tolower(c5));
printf ("La vrai fontcion tolower : %c, %c et %c\n", tolower(a5), tolower(b5), tolower(c5));
printf("----------------------------------------------------------------------------\n");
printf("FONCTION int ft_toupper(int c)\n");	
    int	a6 = 'A';
	int b6 = 'a';
	int c6 = '5';

printf ("Ma fonction pour l exemple A, a et 5 : %c, %c et %c\n",ft_toupper(a6), ft_toupper(b6), ft_toupper(c6));
printf ("La vrai fontcion touper : %c, %c et %c\n", toupper(a6), toupper(b6), toupper(c6));
printf("----------------------------------------------------------------------------\n");
printf("FONCTION int ft_strncmp(const char *str1, const char *str2, size_t nb)\n");
    const char *str1 = "Comparer";
	const char *str2 = "Comparaison";

	printf("Ma fonction pour les exemples 'Comparer' et 'Comparaison' : %d\n", ft_strncmp(str1, str2, 9));
	printf("La fonction strncmp : %d\n", strncmp(str1, str2, 9));
printf("----------------------------------------------------------------------------\n");
printf("FONCTION char *ft_strdup(const char *src)\n");
    const char* source = "Bonjour, monde!";
    char* duplicate = ft_strdup(source);

    if (duplicate != NULL) 
	{
        printf("Chaine source : %s\n", source);
        printf("Chaine dupliquee : %s\n", duplicate);

        free(duplicate);
    } else 
	{
        printf("Echec de l'allocation de memoire.\n");
    }
printf("----------------------------------------------------------------------------\n");
printf("FONCTION char *ft_strchr(const char *str, int c)\n");
const char *str11 = "Comment?";
	int	c9 = 'm';

	printf("Ma fonction pour l exemple 'Comment?' : %s\n", ft_strchr(str11, c9));
	printf("La fonction strchr : %s\n", strchr(str11, c9));
printf("----------------------------------------------------------------------------\n");
printf("FONCTION char *ft_strtrim(const char *str, const char *set)\n");
	char const	*a = "ppop  op o ppppppppo Je n aime pas trop la salade oppppppooopopopopppoop";
	char const	*b = "ppop op o                  pppo";	
printf (" Ma fonction : %s ", ft_strtrim(a, b));
printf("----------------------------------------------------------------------------\n");
printf("FONCTION char *ft_strrchr(const char *str, int c)\n");
    const char *str4 = "Comment?";
	int	c7 = 'm';

printf("Ma fonction pour l exemple 'Comment?' : %s\n", ft_strrchr(str4, c7));
printf("La fonction strrchr : %s\n", strrchr(str4, c7));
printf("----------------------------------------------------------------------------\n");
printf("FONCTION char *ft_substr(const char *s, unsigned int start, size_t len)\n");
	const char *newstr2 = "Bonjour comment ca va?";
	printf("Avec l exemple 'Bonjour comment ca va?', 5, 8\n");
        printf("Ma fonction : %s\n", ft_substr(newstr2, 5, 8));
printf("----------------------------------------------------------------------------\n");
printf("FONCTION char *ft_strjoin(const char *s1, const char *s2)\n");

    const char *chaine13 = "Hello,";
    const char *chaine23 = "world!";

    char *resultat9 = ft_strjoin(chaine13, chaine23);
    printf("Resultat : %s\n", resultat9);

    free(resultat9);

printf("----------------------------------------------------------------------------\n");
printf("FONCTION void ft_bzero(void *blocmem, size_t nb)\n");
	int	*tableau[9];
	ft_bzero(tableau, 7);
	printf("ma fonction : %p\n", tableau);
	bzero(tableau, 7);
printf("la vrai fonction : %p\n", tableau);
printf("----------------------------------------------------------------------------\n");
printf("FONCTION void *ft_calloc(size_t elements, size_t size)\n");
int num_elements = 5; 
    int element_size = sizeof(int); 
    int *arr = (int *)ft_calloc(num_elements, element_size);

    if (arr == NULL) 
	{
        fprintf(stderr, "Allocation de mémoire échouée.\n");
        return 1;
    }

    printf("Tableau alloué et initialisé à zéro :\n");
    for (int i = 0; i < num_elements; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
printf("----------------------------------------------------------------------------\n");
printf("FONCTION void *ft_memset(void *blocmem, int c, size_t len)\n");
	int	*tableau1[9];

	printf("ma fonction : %p\n", ft_memset(tableau1, 8, 7));
	printf("la vrai fonction : %p\n", memset(tableau1, 8, 7));
printf("----------------------------------------------------------------------------\n");
printf("FONCTION void *ft_memchr(const void *str, int c, size_t nb)\n");
    char *chaine = "Bonjour, tout le monde !";
    
    char *resultat1 = ft_memchr(chaine, 'm', strlen(chaine));
    char *resultat2 = memchr(chaine, 'm', strlen(chaine));
    
	if (resultat1 != NULL)
	{	
	printf("Ma fonction :\n");
	printf("Le caractère 'm' a été trouvé à l'index %ld dans la chaîne.\n", resultat1 - chaine);
	}
	if (resultat2 != NULL)
	{
	printf("La fonction memchr :\n");
	printf("Le caractere 'm' a ete trouve a l index %ld dans la chaine.\n", resultat2 - chaine);
	}
printf("----------------------------------------------------------------------------\n");
printf("FONCTION void *ft_memcpy(void *dest, const void *src, size_t nb)\n");
    char source1[] = "Yo Yo Yo Corrige Moi !";
    char destination4[25];


    ft_memcpy(destination4, source1, sizeof(source1));
    printf("Ma fonction : %s\n", destination4);

	memcpy(destination4, source1, sizeof(source1));
    printf("La vrai memcpy : %s\n", destination4);
printf("----------------------------------------------------------------------------\n");
printf("FONCTION void	*ft_memmove(void *dest, const void *src, size_t len)\n");
    char source5[] = "Hello, world!";
    char destination[20];
	char destination15[9];
    ft_memmove(destination, source5, sizeof(source5));
    printf("Ma fonction sans chevauchement: %s\n", destination);
	printf("Ma fonction avec chevauchement: %s\n", destination15);
	memmove(destination, source5, sizeof(source5));
    printf("memmove sans chevauchement: %s\n", destination);
	printf("memmove avec chevauchement: %s\n", destination15);
printf("----------------------------------------------------------------------------\n");
printf("FONCTION int ft_memcmp(const void *str1,	const void *str2, size_t nb)\n");
    char str7[] = "Hello";
    char str8[] = "Hell";

    printf ("Ma fonction cas ou identique :%d\n", ft_memcmp(str7, str8, strlen(str2)));
	printf ("Ma fonction cas ou str1 + petit : %d\n", ft_memcmp(str8, str7, strlen(str1)));
	printf ("Ma fonction cas ou str1 + grand : %d\n", ft_memcmp(str7, str8, strlen(str1)));
printf("----------------------------------------------------------------------------\n");




return (0);
}
