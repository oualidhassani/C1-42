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


# void PmergeMe::Step2(std::vector<int> &vec) {
#     if (vec.size() <= 1)
#         return;
    
#     std::vector<int> smaller_elements;  // Elements that were smaller in pairs
#     std::vector<int> larger_elements;   // Elements that were larger in pairs
#     int unpaired = -1;  // Store unpaired element if odd size
    
#     // Step 1: Separate paired elements (smaller vs larger from each pair)
#     for (size_t i = 0; i + 1 < vec.size(); i += 2) {
#         if (vec[i] <= vec[i + 1]) {
#             smaller_elements.push_back(vec[i]);
#             larger_elements.push_back(vec[i + 1]);
#         } else {
#             smaller_elements.push_back(vec[i + 1]);
#             larger_elements.push_back(vec[i]);
#         }
#     }
    
#     // Handle unpaired element (if odd number of elements)
#     if (vec.size() % 2 == 1) {
#         unpaired = vec.back();
#     }
    
#     // Step 2: Recursively sort the larger elements
#     if (larger_elements.size() > 1) {
#         Step2(larger_elements);
#     }
    
#     // Step 3: Build the main chain starting with the first smaller element
#     // and all larger elements
#     std::vector<int> main_chain;
#     if (!smaller_elements.empty()) {
#         main_chain.push_back(smaller_elements[0]);  // First smaller element goes first
#     }
    
#     // Add all larger elements to main chain
#     for (size_t i = 0; i < larger_elements.size(); i++) {
#         main_chain.push_back(larger_elements[i]);
#     }
    
#     // Step 4: Insert remaining smaller elements using binary insertion
#     // Insert in reverse order for better performance (Ford-Johnson strategy)
#     for (int i = smaller_elements.size() - 1; i >= 1; i--) {
#         binary_insertion(main_chain, smaller_elements[i]);
#     }
    
#     // Step 5: Insert unpaired element if exists
#     if (unpaired != -1) {
#         binary_insertion(main_chain, unpaired);
#     }
    
#     vec = main_chain;
# }