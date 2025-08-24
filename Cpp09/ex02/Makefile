NAME = PmergeMe

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PmergeMe.cpp

OBJ = $(SRCS:.cpp=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
		$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all
