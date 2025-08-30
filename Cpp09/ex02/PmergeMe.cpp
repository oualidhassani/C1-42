#include "PmergeMe.hpp"

void swapGroups_deq(std::deque<int>& arr, int leftStart, int rightStart, int groupSize)
{
      for (int i = 0; i < groupSize; i++) 
    {
        std::swap(arr[leftStart + i], arr[rightStart + i]);
    }
}

void binary_insertion_deq(std::deque<int> &deq, int insert_num)
{
    if (deq.empty()) 
    {
        deq.push_back(insert_num);
        return;
    }
    int left = 0;
    int right_max = deq.size();
    while(right_max > left)
    {
        int mid = left + (right_max- left) / 2;
        if(deq[mid] > insert_num)
            right_max = mid;
        else
        left = mid + 1;
    }
    deq.insert(deq.begin() + left, insert_num);   
}

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
        this->deq = other.deq;
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

std::deque<int> &PmergeMe::getdeq()
{
    return this->deq;
}

void swapGroups(std::vector<int>& arr, int leftStart, int rightStart, int groupSize) 
{
    for (int i = 0; i < groupSize; i++) 
    {
        std::swap(arr[leftStart + i], arr[rightStart + i]);
    }

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


void Step1_deq(std::deque<int> &deq)
{

   for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        if (compare(deq[i + 1], deq[i]))
        {
            std::swap(deq[i], deq[i + 1]);
        }
    }
    size_t level = 1;

    while(static_cast<std::deque<int>::size_type>((1 << level) * 2) <= deq.size())
    {

        int levgroup = level << 1; // kola group xhal fih mn num
        int pair_size = levgroup * 2; // xhal mn pair 3dna (4, 2 grps of 2)
        int num_pair = deq.size() / pair_size; // check wch kynin 2 pairs , need to have num zawji in res


        for(int i = 0; i < num_pair ; i++)
        {
            int leftstart = i * pair_size;
            int rightstart = leftstart + levgroup;

            int leftmaxside = leftstart + levgroup - 1;
            int rightmaxside = rightstart + levgroup - 1;

            if(compare(deq[rightmaxside], deq[leftmaxside]))
            {
                swapGroups_deq(deq, leftstart, rightstart, levgroup);
            }

        }
        level++;
    }
}
void Step2_deq(std::deque<int> &deq)
{
    if (deq.size() <= 1) return;
    
    std::deque<int> larger_pair;
    std::deque<int> smaller_pair;
    
    int odd_num = -1;
    bool has_odd_num = (deq.size() % 2 == 1);
    if (has_odd_num) 
    {
        odd_num = deq.back();
        deq.pop_back();
    }
    
    for(size_t i = 0; i < deq.size(); i += 2)
    {
        larger_pair.push_back(deq[i + 1]);
        smaller_pair.push_back(deq[i]);
    }
    
    std::deque<int> sorted_sequence;
    if (!larger_pair.empty()) 
    {
        sorted_sequence.push_back(larger_pair[0]);
    }
    
    for (size_t i = 0; i < smaller_pair.size(); i++) 
    {
        binary_insertion_deq(sorted_sequence, smaller_pair[i]);
        
        if (i + 1 < larger_pair.size()) 
        {
            binary_insertion_deq(sorted_sequence, larger_pair[i + 1]);
        }
    }
    
    if (has_odd_num) 
    {
        binary_insertion_deq(sorted_sequence, odd_num);
    }
    
    deq = sorted_sequence;
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
    std::cout << std::endl; 
    
    struct timeval start, end;
    gettimeofday(&start, NULL);

    Step1(vec);
    Step2(vec);

    gettimeofday(&end, NULL);

    double elapsed_us = (end.tv_sec - start.tv_sec) * 1000000.0 +
                       (end.tv_usec - start.tv_usec);

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(5);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << elapsed_us << " us" << std::endl;
}


void PmergeMe::sort_deq(std::deque<int> &deq)
{
    if(deq.size() <= 1)
        return ; 
    
    std::cout << "Before: ";
    for(size_t i = 0; i < deq.size() ; i++)
    {
        std::cout  << deq[i] << " ";
    }
    std::cout << std::endl; 
    
    struct timeval start, end;
    gettimeofday(&start, NULL);

    Step1_deq(deq);
    Step2_deq(deq);

    gettimeofday(&end, NULL);

    double elapsed_us = (end.tv_sec - start.tv_sec) * 1000000.0 +
                       (end.tv_usec - start.tv_usec);

    std::cout << "After: ";
    for (size_t i = 0; i < deq.size(); i++)
        std::cout << deq[i] << " ";
    std::cout << std::endl;

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(5);
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : "
              << elapsed_us << " us" << std::endl;
}