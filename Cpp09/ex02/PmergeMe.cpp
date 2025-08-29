#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->vec = other.vec;
    }
    return *this;
}

bool compare(int a, int b) 
{
    return a < b; 
}

std::vector<int> &PmergeMe::getvec()
{
    return this->vec;
}

void swapGroups(std::vector<int>& arr, int leftStart, int rightStart, int groupSize) 
{
    for (int i = 0; i < groupSize; i++) 
    {
        std::swap(arr[leftStart + i], arr[rightStart + i]);
    }

}

void binary_insertion(std::vector<int> &vect, int insert_num)
{

    if (vect.empty()) 
    {
        vect.push_back(insert_num);
        return;
    }
    int left = 0;
    int right_max = vect.size();
    while(right_max > left)
    {
        int mid = left + (right_max- left) / 2;
        if(vect[mid] > insert_num)
            right_max = mid;
        else
        left = mid + 1;
    }
    vect.insert(vect.begin() + left, insert_num);   
}


void Step1(std::vector<int> &vec)
{

   for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        if (compare(vec[i + 1], vec[i]))
        {
            std::swap(vec[i], vec[i + 1]);
        }
    }
    size_t level = 1;

    while(static_cast<std::vector<int>::size_type>((1 << level) * 2) <= vec.size())
    {

        int levgroup = level << 1; // kola group xhal fih mn num
        int pair_size = levgroup * 2; // xhal mn pair 3dna (4, 2 grps of 2)
        int num_pair = vec.size() / pair_size; // check wch kynin 2 pairs , need to have num zawji in res


        for(int i = 0; i < num_pair ; i++)
        {
            int leftstart = i * pair_size;
            int rightstart = leftstart + levgroup;

            int leftmaxside = leftstart + levgroup - 1;
            int rightmaxside = rightstart + levgroup - 1;

            if(compare(vec[rightmaxside], vec[leftmaxside]))
            {
                swapGroups(vec, leftstart, rightstart, levgroup);
            }

        }
        level++;
    }
}


void PmergeMe::Step2(std::vector<int> &vec)
{
    if (vec.size() <= 1) return;
    
    std::vector<int> larger_pair;
    std::vector<int> smaller_pair;
    
    int odd_num = -1;
    bool has_odd_num = (vec.size() % 2 == 1);
    if (has_odd_num) 
    {
        odd_num = vec.back();
        vec.pop_back();
    }
    
    for(size_t i = 0; i < vec.size(); i += 2)
    {
        larger_pair.push_back(vec[i + 1]);
        smaller_pair.push_back(vec[i]);
    }
    
    std::vector<int> sorted_sequence;
    if (!larger_pair.empty()) 
    {
        sorted_sequence.push_back(larger_pair[0]);
    }
    
    for (size_t i = 0; i < smaller_pair.size(); i++) 
    {
        binary_insertion(sorted_sequence, smaller_pair[i]);
        
        if (i + 1 < larger_pair.size()) 
        {
            binary_insertion(sorted_sequence, larger_pair[i + 1]);
        }
    }
    
    if (has_odd_num) 
    {
        binary_insertion(sorted_sequence, odd_num);
    }
    
    vec = sorted_sequence;
}

void PmergeMe::sort(std::vector<int> &vec)
{

    if(vec.size() <= 1)
        return ; 
    std::cout << "Before: ";
    for(size_t i = 0; i < vec.size() ; i++)
    {
        std::cout  << vec[i] << " ";
    }
    
    clock_t start = clock();
    
    Step1(vec);
    Step2(vec);
    std::cout << std::endl << "After: ";
    for(size_t i = 0; i < vec.size() ; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

