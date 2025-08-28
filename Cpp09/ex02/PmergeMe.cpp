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
    
    std::vector<int> main_chain;
    std::vector<int> pending;
    
    // Handle the straggler (odd element) if exists
    int straggler = -1;
    bool has_straggler = (vec.size() % 2 == 1);
    if (has_straggler) {
        straggler = vec.back();
        vec.pop_back();
    }
    
    // Separate into main chain (larger elements) and pending (smaller elements)
    for(size_t i = 0; i < vec.size(); i += 2)
    {
        main_chain.push_back(vec[i + 1]); // larger element goes to main chain
        pending.push_back(vec[i]);        // smaller element goes to pending
    }
    
    // Start with an empty sorted sequence and insert the first element of main_chain
    std::vector<int> sorted_sequence;
    if (!main_chain.empty()) {
        sorted_sequence.push_back(main_chain[0]);
    }
    
    // Insert pending elements in order (each pending[i] is smaller than main_chain[i])
    // We know pending[0] < main_chain[0], so it goes at the beginning
    for (size_t i = 0; i < pending.size(); i++) 
    {
        binary_insertion(sorted_sequence, pending[i]);
        
        // Then insert the corresponding main_chain element (if not already inserted)
        if (i + 1 < main_chain.size()) {
            binary_insertion(sorted_sequence, main_chain[i + 1]);
        }
    }
    
    // Insert straggler if it exists
    if (has_straggler) {
        binary_insertion(sorted_sequence, straggler);
    }
    
    vec = sorted_sequence;
}

void PmergeMe::sort(std::vector<int> &vec)
{

    if(vec.size() <= 1)
        return ; 
    
    Step1(vec);
    Step2(vec);
    for(size_t i = 0; i < vec.size() ; i++)
    {
        std::cout << vec[i] << " ";
    }

}

