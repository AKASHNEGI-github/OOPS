// DSA NOTES

// LEETCODE - GENERAL

371. Sum of Two Integers
class Solution {
public:
    int getSum(int a, int b) 
    {
      while(b != 0)
      {
        int temp = (a & b) << 1;
        a = a ^ b;
        b = temp;
      } 
      return a;   
    }
};

2769. Find the Maximum Achievable Number
class Solution {
public:
    int theMaximumAchievableX(int num, int t) 
    {
      return (num + (2*t));
    }
};

2520. Count the Digits That Divide a Number
class Solution {
public:
    int countDigits(int num) 
    {
        int ans = 0;
        int temp = num;
        while(temp > 0)
        {
            int mod = temp%10;
            temp = temp/10; 
            if(num%mod == 0)
            {
                ans++;
            }
        } 
        return ans;   
    }
};

1342. Number of Steps to Reduce a Number to Zero
class Solution {
public:
    int numberOfSteps(int num) 
    {
        int ans = 0;
        while(num != 0)
        {
            ans++;
            if(num%2 == 0)
            {
                num = num/2;
            }
            else
            {
                num = num-1;
            }    
        }
        return ans;
    }
};

2180. Count Integers With Even Digit Sum
class Solution {
public:
    int digitSum(int n)
    {
      int digit_sum = 0;
      while(n > 0)
      {
        digit_sum = digit_sum + (n%10);
        n = n/10;
      }
      return digit_sum;
    }
    int countEven(int num) 
    {
      int ans = 0;
      while(num > 0)
      {
        int sum = digitSum(num);
        if(sum%2 == 0)
        {
          ans++;
        }
        num--;
      }
      return ans; 
    }
};

2119. A Number After a Double Reversal
class Solution {
public:
    int reverseNumber(int n)
    {
      int reverse = 0;
      while(n > 0)
      {
        reverse = reverse * 10 + (n%10);
        n = n/10;
      }
      return reverse;
    }
    bool isSameAfterReversals(int num) 
    {
      int n = num;
      n = reverseNumber(n);
      n = reverseNumber(n);
      if(n == num)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
};

2544. Alternating Digit Sum
class Solution {
public:
    int alternateDigitSum(int n) 
    {
        int ans = 0;
        string s = to_string(n);
        for(int i=0 ; i<s.size() ; i++)
        {
            int num = (s[i] - '0');
            if(i%2 != 0)
            {
                ans = ans - s[i];
            }
            else
            {  
                ans = ans + s[i];
            }
        }  
        return ans;  
    }
};

1688. Count of Matches in Tournament
class Solution {
public:
    int numberOfMatches(int n) 
    {
        int matches = 0;
        while(n > 1)
        {
            if(n%2 == 0)
            {
                matches = matches + (n/2);
                n = (n/2);
            }
            else
            {
                matches = matches + (n/2);
                n = (n/2) + 1;
            } 
        }
        return matches;   
    }
};

1523. Count Odd Numbers in an Interval Range
class Solution {
public:
    int countOdds(int low, int high) 
    {
      int ans = 0;
      for(int i=low ; i<=high ; i++)
      {
        if(i%2 != 0)
        {
          ans++;
        }
      }  
      return ans;  
    }
};

2169. Count Operations to Obtain Zero
class Solution {
public:
    int countOperations(int num1, int num2) 
    {
      int operation = 0;
      while(num1 > 0 && num2 > 0)  
      {
        if(num1 > num2)
        {
          num1 = num1 - num2;
          operation++;
        }
        else
        {
          num2 = num2 - num1;
          operation++;
        }
      }
      return operation;
    }
};

2651. Calculate Delayed Arrival Time
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) 
    {
        int ans = arrivalTime + delayedTime;
        if (ans >= 24)
        {
            return (ans - 24);
        } 
        else
        {
            return ans;
        }
    }
};

1518. Water Bottles
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int sum = numBottles;
        while(numBottles >= numExchange)
        {
            int quotient = numBottles/numExchange;
            int rem = numBottles%numExchange;
            sum = sum + quotient;
            numBottles = quotient + rem;
        }  
        return sum;  
    }
};

507. Perfect Number
class Solution {
public:
    bool checkPerfectNumber(int num) 
    {
      int sum = 0;
      for(int i=1 ; i<num ; i++)
      {
        if(num % i == 0)
        {
          sum = sum + i;
        }
      }  
      if(sum == num)  
      {
        return true;
      }
      else
      {
        return false;
      }
    }
};

231. Power of Two
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
      for(int i=0 ; i<=30 ; i++)
      {
        int ans = pow(2 , i);
        if(ans == n)
        {
          return true;
        } 
      }
      return false;   
    }
};

7. Reverse Integer
class Solution {
public:
    int reverse(int x) 
    {
      int ans = 0;
      while(x != 0)
      {
        if( ( ans < INT_MIN/10 ) || ( ans > INT_MAX/10) )
        {
          return 0;
        }
        int mod = x % 10;
        ans = (ans * 10) + mod;
        x = x / 10;
      }
      return ans;    
    }
};

258. Add Digits
class Solution {
public:
    int addDigits(int num) 
    {
      if(num / 10 == 0)
      {
        return num;
      }
      int sum = 0;
      while(num > 0)
      {
        sum = sum + num % 10;
        num = num / 10;
      } 
      return addDigits(sum);
    }
};

202. Happy Number
class Solution {
public:
    bool isHappy(int n) 
    {
      set<int> myset;
      while(1)
      {
        int sum = 0;
        while(n)
        {
          int mod = n%10;
          sum = sum + mod * mod;
          n = n/10;
        }
        if(sum == 1)
        {
          return true;
        }
        else if( myset.find(sum) != myset.end() )
        {
          return false;
        }
        myset.insert(sum);
        n = sum;
      }
      return false;
    }
};

69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) 
    {
        int start = 1;
        int end = x;
        if(x == 0)
        {
            return x;
        }
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(mid == x / mid)
            {
                return mid;
                
            }
            else if(mid < x / mid)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }    
        return end;
    }
};

// LEETCODE - ARRAYS

66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
      for(int i=digits.size()-1 ; i>=0 ; i--)
      {
        if(digits[i] != 9)
        {
          digits[i]++;
          break;
        }
        else
        {
          digits[i] = 0;
        }
      }
      if(digits[0] == 0)
      {
        digits.push_back(0);
        digits[0] = 1;
      }
      return digits;
    }
};

728. Self Dividing Numbers
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
      vector<int> ans;
      for(int i=left ; i<=right ; i++)
      {
        int temp = i;
        int flag = 0;
        while(temp > 0)
        {
          int digit = temp%10;
          if( digit == 0 || i%digit != 0)
          {
            flag = 1;
            break;
          }
          else
          {
            temp = temp/10;
          }
        }
        if(flag == 0)
        {
          ans.push_back(i);
        }
      }    
      return ans;
    }
};

2455. Average Value of Even Numbers That Are Divisible by Three
class Solution {
public:
    int averageValue(vector<int>& nums) 
    {
      int sum = 0;
      int n = 0;
      for(int i=0 ; i<nums.size() ; i++)
      {
        if(nums[i]%2 == 0 && nums[i]%3 == 0)
        {
          sum = sum + nums[i];
          n++;
        }
      }
      if(n == 0)
      {
        return 0;
      }
      else
      {
        return (sum/n);   
      }
    }
};

268. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int expected_sum =  n*(n+1)/2;
        int current_sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            current_sum = current_sum + nums[i];
        }
        return (expected_sum - current_sum);
    }
};

1979. Find Greatest Common Divisor of Array
class Solution {
public:
    int gcd(int n1 , int n2)
    {
      while(n2 != 0)
      {
        int rem = n1 % n2;
        n1 = n2;
        n2 = rem;
      }
      return n1;
    }
    int findGCD(vector<int>& nums) 
    {
      sort( nums.begin() , nums.end() , greater<int>() );
      return gcd( nums[0] , nums[nums.size()-1] );
    }
};

1486. XOR Operation in an Array
class Solution {
public:
    int xorOperation(int n, int start) 
    {
        int ans = 0;
        vector<int> nums(n);
        for(int i=0 ; i<n ; i++)
        {
            nums[i] = start + 2 * i;
        }  
        for(int i=0 ; i<n ; i++)
        {
            ans = ans^nums[i];
        } 
        return ans; 
    }
};

349. Intersection of Two Arrays
class Solution {
public:
    bool search(vector<int> v , int key)
    {
        for(int i=0 ; i<v.size() ; i++)
        {
            if(v[i] == key)
            {
                return true;
            }
        }
        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        for(int i=0 ; i<nums1.size() ; i++)
        {
            for(int j=0 ; j<nums2.size() ; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    if(! search(ans , nums1[i]))
                    {
                        ans.push_back(nums1[i]);
                    }
                }
            }
        }  
        return ans;  
    }
};

1287. Element Appearing More Than 25% In Sorted Array
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
      int ans = 0;
      for(int i=0 ; i<arr.size() ; i++)
      {
        int count = 0;
        for(int j=i ; j<arr.size() ; j++)
        {
          if(arr[i] == arr[j])
          {
            count++;
          }
        }
        if(count > arr.size()/4)
        {
          ans = arr[i];
        }
      }
      return ans;    
    }
};

1619. Mean of Array After Removing Some Elements
class Solution {
public:
    double trimMean(vector<int>& arr) 
    {
      int start = arr.size()/20;
      int end = arr.size() - start;
      double sum = 0;
      double count = arr.size() - arr.size()/10;
      sort(arr.begin() , arr.end());
      for(int i=start ; i<end ; i++)
      {
        sum = sum + arr[i];
      }
      return sum/count;
    }
};

283. Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
      int left = 0;
      int right = 0;
      for(int i=0 ; i<nums.size() ; i++)
      {
        if(nums[right] == 0)
        {
          right++;
        }  
        else if(nums[right] != 0)
        {
          swap(nums[left] , nums[right]);
          left++;
          right++;
        }
      } 
    }
};

169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
      int majority_element = nums[0];
      int count = 1;
      for(int i=1 ; i<nums.size() ; i++)
      {
        if(nums[i] == majority_element)
        {
          count++;
        }
        else
        {
          count--;
          if(count == 0)
          {
            majority_element = nums[i];
            count++;
          }
        }
      }
      return majority_element;    
    }
};

1491. Average Salary Excluding the Minimum and Maximum Salary
class Solution {
public:
    double average(vector<int>& salary) 
    {
      double sum = 0;
      double count = 0;
      sort(salary.begin() , salary.end());
      for(int i=1 ; i<salary.size()-1 ; i++)
      {
        sum = sum + salary[i];
        count++;
      }    
      return sum/count;
    }
};

2460. Apply Operations to an Array
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
      vector<int> ans;
     for(int i=0 ; i<nums.size()-1 ; i++)
     {
       if(nums[i] == nums[i+1])
       {
         nums[i] = nums[i] * 2;
         nums[i+1] = 0;
       }
     }
     for(int i=0 ; i<nums.size() ; i++)
     {
      if(nums[i] != 0)
      {
        ans.push_back(nums[i]);
      }
     } 
     for(int i=0 ; i<nums.size() ; i++)
     {
      if(nums[i] == 0)
      {
        ans.push_back(nums[i]);
      }
     }
     return ans;  
    }
};

2148. Count Elements With Strictly Smaller and Greater Elements 
class Solution {
public:
    int countElements(vector<int>& nums) 
    {
      int count = 0;
      sort(nums.begin() , nums.end());
      for(int i=1 ; i<nums.size()-1 ; i++)
      {
        if(nums[0] < nums[i] && nums[i] < nums[nums.size()-1])
        {
          count++;
        }
      }
      return count;    
    }
};

1394. Find Lucky Integer in an Array
class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
      sort(arr.begin() , arr.end());
      int ans = -1;
      for(int i=0 ; i<arr.size() ; i++)
      {
        int count = 0;
        for(int j=0 ; j<arr.size() ; j++)
        {
          if(arr[i] == arr[j])
          {
            count++;
          }
        }
        if(count == arr[i])
        {
          ans = arr[i];
        }
      }
      return ans;    
    }
};

2778. Sum of Squares of Special Elements 
class Solution {
public:
    int sumOfSquares(vector<int>& nums) 
    {
      int ans = 0;
      int n = nums.size();
      for(int i=0 ; i<n ; i++)
      {
        if(n % (i+1) == 0)
        {
          ans = ans + (nums[i] * nums[i]);
        }
      }
      return ans;    
    }
};

1748. Sum of Unique Elements
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
      int sum = 0;
      for(int i=0 ; i<nums.size() ; i++)
      {
        int flag = 0;
        for(int j=0 ; j<nums.size() ; j++)
        {
          if(nums[i] == nums[j])
          {
            flag++;
          }
        }
        if(flag == 1)
        {
          sum = sum + nums[i];
        }
      }
      return sum;
    }
};

2656. Maximum Sum With Exactly K Elements 
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) 
    {
      int sum = 0;
      sort(nums.begin() , nums.end());
      for(int i=0 ; i<k ; i++)
      {
        sum = sum + nums[nums.size()-1];
        nums[nums.size()-1] = nums[nums.size()-1] + 1;
      }
      return sum;
    }
};

2824. Count Pairs Whose Sum is Less than Target
class Solution {
public:
    int countPairs(vector<int>& nums, int target) 
    {
      int count = 0;
      for(int i=0 ; i<nums.size() ; i++)
      {
        for(int j=i+1 ; j<nums.size() ; j++)
        {
          if(nums[i] + nums[j] < target)
          {
            count++;
          }
        }
      }
      return count;    
    }
};

2176. Count Equal and Divisible Pairs in an Array
class Solution {
public:
    int countPairs(vector<int>& nums, int k) 
    {
      int ans = 0;
      for(int i=0 ; i<nums.size() ; i++)
      {
        for(int j=i+1 ; j<nums.size() ; j++)
        {
          if( nums[i] == nums[j] && (i*j)%k ==0 )
          {
            ans++;
          }
        }
      }
      return ans;   
    }
};

2006. Count Number of Pairs With Absolute Difference K
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
      int ans = 0;
      for(int i=0 ; i<nums.size() ; i++)
      {
        for(int j=i+1 ; j<nums.size() ; j++)
        {
          if( abs(nums[i] - nums[j]) == k )
          {
            ans++;
          }
        }
      }
      return ans;    
    }
};

2485. Find the Pivot Integer
class Solution {
public:
    int pivotInteger(int n) 
    {
      if(n == 1)
      {
        return 1;
      }
      int sum = n*(n+1)/2;
      if( ceil(sqrt(sum)) == floor(sqrt(sum)) )
      {
        return sqrt(sum);
      }
      else
      {
        return -1;
      }   
    }
};

1450. Number of Students Doing Homework at a Given Time
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) 
    {
      int ans = 0;
      for(int i=0 ; i<startTime.size() ; i++)
      {
        if(queryTime >= startTime[i] && queryTime <= endTime[i])
        {
          ans++;
        }
      }
      return ans;    
    }
};

2733. Neither Minimum nor Maximum
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) 
    {
      sort(nums.begin() , nums.end());
      for(int i=1 ; i<nums.size()-1 ; i++)
      {
        if(nums[i] > nums[0] && nums[i] < nums[nums.size()-1])
        {
          return nums[i];
        }
      }
      return -1;    
    }
};

1295. Find Numbers with Even Number of Digits
class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
      int ans = 0;
      for(int i=0 ; i<nums.size() ; i++)
      {
        int digits = 0;
        while(nums[i] > 0)
        {
          digits++;
          nums[i] = nums[i]/10;
        }
        if(digits % 2 == 0)
        {
          ans++;
        }
      }
      return ans;    
    }
};

238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
      int product = 1;
      int n = nums.size();
      vector<int> ans;
      for(int i=0 ; i<n ; i++)
      {
        product = product * nums[i];
        ans.push_back(product);
      }
      product = 1;
      for(int i=n-1 ; i>0 ; i--)
      {
        ans[i] = ans[i-1] * product;
        product = product * nums[i];
      }
      ans[0] = product;
      return ans; 
    }
};

189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
      vector<int> v(nums.size());
      for(int i=0 ; i<nums.size() ; i++)
      {
        v[(i+k) % nums.size()] = nums[i];
      }    
      nums = v;
    }
};

724. Find Pivot Index
class Solution {
public:
    int sum(vector<int>& v , int start , int end)
    {
        int sum = 0;
        for(int i=start ; i<=end ; i++)
        {
            sum = sum + v[i];
        }
        return sum;
    }
    
    int pivotIndex(vector<int>& nums) 
    {
        for(int i=0 ; i<nums.size() ; i++)
        {
            int left_sum = sum(nums , 0 , i-1);
            int right_sum = sum(nums , i+1 , nums.size()-1);
            if(left_sum == right_sum)
            {
                return i;
            }
        }
        return -1;    
    }
};

75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
      for(int i=0 ; i<nums.size()-1 ; i++)
      {
        int min_index = i;
        for(int j=i+1 ; j<nums.size() ; j++)
        {
          if(nums[j] < nums[min_index])
          {
            min_index = j;
          }
        }
        swap(nums[i] , nums[min_index]);
      }    
    }
};

1877. Minimize Maximum Pair Sum in Array
class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
      sort(nums.begin() , nums.end());
      int i = 0;
      int j = nums.size() - 1;
      int max_sum = 0;
      while(i < j)
      {
        int sum = nums[i] + nums[j];
        max_sum = max(sum , max_sum);
        i++;
        j--;
      }
      return max_sum;
    }
};

1551. Minimum Operations to Make Array Equal
class Solution {
public:
    int minOperations(int n) 
    {
      if(n % 2 != 0)
      {
        n = n / 2;
        return n * (n + 1);
      }
      else
      {
        n = n / 2;
        return n * n;
      }
    }    
};

1833. Maximum Ice Cream Bars
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
      int ice_cream_bars = 0;
      sort(costs.begin() , costs.end());
      int price = 0;
      for(int i = 0 ; i < costs.size() ; i++)
      {
        price = price + costs[i];
        if(price <= coins)
        {
          ice_cream_bars++;
        }
        else
        {
          break;
        }
      }
      return ice_cream_bars;
    }
};

1769. Minimum Number of Operations to Move All Balls to Each Box
class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
      vector<int> ans;
      for(int i=0 ; i<boxes.size() ; i++)
      {
        int operations = 0;
        for(int j=0 ; j<boxes.size() ; j++)
        {
          if(boxes[j] == '1')
          {
            operations = operations + abs(j - i);
          }
        }
        ans.push_back(operations);
      }
      return ans;    
    }
};

1561. Maximum Number of Coins You Can Get
class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
      int max_coins = 0;
      sort(piles.begin() , piles.end());
      int  max_coins_index = (piles.size() - 2);
      for(int i=0 ; i<piles.size()/3 ; i++)
      {
        max_coins = max_coins + piles[ max_coins_index];
         max_coins_index =  max_coins_index - 2;
      }
      return max_coins;
    }
};

2079. Watering Plants
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
      int steps = 0;
      int current_capacity = capacity;
      for(int i=0 ; i<plants.size() ; i++)
      {
        if(plants[i] <= current_capacity)
        {
          current_capacity = current_capacity - plants[i];
          steps++;
        }
        else
        {
          current_capacity = capacity;
          current_capacity = current_capacity - plants[i];
          steps = steps + (2*i + 1);
        }
      }
      return steps;      
    }
};

1299. Replace Elements with Greatest Element on Right Side
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
      int greatest = -1;
      for(int i=arr.size()-1 ; i>=0 ; i--)
      {
        int temp = arr[i];
        arr[i] = greatest;
        if(temp > greatest)
        {
          greatest = temp;
        }
      }
      return arr;    
    }
};

2149. Rearrange Array Elements by Sign
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
      vector<int> v1;
      vector<int> v2;
      for(int i=0 ; i<nums.size() ; i++)
      {
        if(nums[i] > 0)
        {
          v1.push_back(nums[i]);
        }
        else if(nums[i] < 0)
        {
          v2.push_back(nums[i]);
        }
      }
      nums.clear();
      for(int i=0 ; i<v1.size() ; i++)
      {
        nums.push_back(v1[i]);
        nums.push_back(v2[i]);
      } 
      return nums;
    }
};

1282. Group the People Given the Group Size They Belong To
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
      vector<vector<int>> ans;
      for(int i=1 ; i<=*max_element(groupSizes.begin() , groupSizes.end()) ; i++)
      {
        vector<int> subans;
        for(int j=0 ; j<groupSizes.size() ; j++)
        {
          if(groupSizes[j] == i)
          {
            if(subans.size() >= i)
            {
              ans.push_back(subans);
              subans.clear();
            }
            subans.push_back(j);
          }
        }
        if(subans.size() > 0)
        {
          ans.push_back(subans);
        }
      }
      return ans;
    }
};

442. Find All Duplicates in an Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
      vector<int> ans;
      sort(nums.begin() , nums.end());
      for(int i=0 ; i<nums.size()-1 ; i++)
      {
        if(nums[i] == nums[i+1])
        {
          ans.push_back(nums[i]);
        }
      }
      return ans;    
    }
};

1991. Find the Middle Index in Array
class Solution {
public:
    int sum(vector<int>& v , int start , int end)
    {
        int sum = 0;
        for(int i=start ; i<=end ; i++)
        {
            sum = sum + v[i];
        }
        return sum;
    }
    
    int findMiddleIndex(vector<int>& nums) 
    {
        for(int i=0 ; i<nums.size() ; i++)
        {
            int left_sum = sum(nums , 0 , i-1);
            int right_sum = sum(nums , i+1 , nums.size()-1);
            if(left_sum == right_sum)
            {
                return i;
            }
        }
        return -1;    
    }
};

852. Peak Index in a Mountain Array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
      int start = 0;
      int end = arr.size() - 1;
      while(start < end)
      {
        int mid = start + (end - start)/2;
        if(arr[mid] < arr[mid + 1])
        {
          start = mid + 1;
        }
        else
        {
          end = mid;
        }
      }
      return start;
    }
};

34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    int firstOccurrence(vector<int>& nums , int start , int end , int target)
    {
        int first_occurrence = -1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
            first_occurrence = mid;
            end = mid - 1;
            }
            else if(nums[mid] < target)
            {
            start = mid + 1;
            }
            else
            {
            end = mid - 1;
            }
        }
        return first_occurrence;
    }

    int lastOccurrence(vector<int>& nums , int start , int end , int target)
    {
        int last_occurrence = -1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
            last_occurrence = mid;
            start = mid + 1;
            }
            else if(nums[mid] < target)
            {
            start = mid + 1;
            }
            else
            {
            end = mid - 1;
            }
        }
        return last_occurrence;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
      vector<int> ans;    
      ans.push_back( firstOccurrence(nums , 0 , nums.size()-1 , target) );
      ans.push_back( lastOccurrence(nums , 0 , nums.size()-1 , target) );
      return ans;
    }
};

162. Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] < nums[mid+1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start;   
    }
};



// LEETCODE - MATRIX
// LEETCODE - STRING

1221. Split a String in Balanced Strings
class Solution {
public:
    int balancedStringSplit(string s) 
    {
      int count_R = 0;
      int count_L = 0;
      int ans = 0;
      for(int i=0 ; i<s.size() ; i++)
      {
        if(s[i] == 'R')
        {
          count_R++;
        }
        else
        {
          count_L++;
        }
        if(count_R == count_L)
        {
          ans++;
        }
      }
      return ans;    
    }
};

1945. Sum of Digits of String After Convert
class Solution {
public:
    string sum_of_digits(string temp)
    {
      int sum = 0;
      for(int i=0 ; i<temp.size() ; i++)
      {
        sum = sum + (temp[i] - 48);
      }
      return to_string(sum);
    }

    int getLucky(string s, int k) 
    {
      string temp;
      for(int i=0 ; i<s.size() ; i++)
      {
        temp = temp + to_string(s[i] - 96);
      } 
      while(k > 0)
      {
        temp = sum_of_digits(temp);
        k--;
      } 
      return stoi(temp);   
    }
};

1844. Replace All Digits with Characters
class Solution {
public:
    string replaceDigits(string s) {
      string ans;
      for(int i=0; i<s.size(); i++)
      {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
          ans.push_back(s[i]);
        }
        else
        {
          ans.push_back(s[i-1] + s[i] - '0');
        }
      }
      return ans;
    }
};

2496. Maximum Value of a String in an Array
class Solution {
public:
    int maximumValue(vector<string>& strs) 
    {
      int max_length = 0;
      for(int i=0 ; i<strs.size() ; i++)
      {
        int length = 0;
        string s = strs[i];
        for(int j=0 ; j<s.size() ; j++)
        {
          if( (s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122) )
          {
            length = s.length();
            break;
          }
          else
          {
            length = stoi(s);
          }
        }
        if(length > max_length)
        {
          max_length = length;
        }
      }
      return max_length;    
    }
};

2785. Sort Vowels in a String
class Solution {
public:
    string sortVowels(string s) 
    {
      vector<int> v;
      string ans;
      for(int i=0 ; i<s.size() ; i++)
      {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
           {
             v.push_back(s[i]);
           }
      }
      sort(v.begin() , v.end());
      int j = 0;
      for(int i=0 ; i<s.size() ; i++)
      {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
          ans.push_back(v[j]);
          j++;
        }
        else
        {
          ans.push_back(s[i]);
        }
      }
      return ans;
    }
};

// LEETCODE - LINKED LIST

2807. Insert Greatest Common Divisors in Linked List
class Solution {
public:
    int gcd(int n1 , int n2)
    {
      if(n2 == 0)
      {
        return n1;
      }
      return gcd(n2 , n1 % n2);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
      ListNode* ptr = head;
      while(ptr->next != NULL)
      {
        ListNode* temp = new ListNode( gcd(ptr->val , ptr->next->val) );
        temp->next = ptr->next;
        ptr->next = temp;
        ptr = temp->next;
      }
      return head;    
    }
};

237. Delete Node in a Linked List
class Solution {
public:
    void deleteNode(ListNode* node) {
      node->val = node->next->val;
      node->next = node->next->next;
    }
};

141. Linked List Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) // Floyd's Cycle Detection
    {
        if(head == NULL || head->next == NULL)
        {
            return false;
        }  
        ListNode *slow = head;
        ListNode *fast = head; 
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};

142. Linked List Cycle II
class Solution {
public:
    bool hasCycle(ListNode *head) // Floyd's Cycle Detection
    {
        if(head == NULL || head->next == NULL)
        {
            return false;
        }  
        ListNode *slow = head;
        ListNode *fast = head; 
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }

    ListNode *detectCycle(ListNode *head) // Floyd's Cycle Detection
    {
        if(hasCycle(head))
        {
            ListNode *slow = head;
            ListNode *fast = head; 
            while(fast != NULL)
            {
                fast = fast->next;
                if(fast != NULL)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                if(fast == slow)
                {
                    slow = head;
                    break;
                }
            } 
            while(slow != fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        return NULL;
    }
};

25. Reverse Nodes in k-Group
class Solution {
public:
    int getLength(ListNode* head)
    {
        int length = 0;
        ListNode * ptr = head;
        while(ptr != NULL)
        {
            length++;
            ptr = ptr->next;
        }
        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL)
        {
            return NULL;
        }    
        if(k > getLength(head))
        {
            return head;
        }
        ListNode *current = head;
        ListNode *previous = NULL;
        ListNode *forward = NULL;
        int count = 0;
        while(count < k)
        {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
            count++;
        }
        // Recursive call
        if(forward != NULL)    // Nodes still left
        {
            head->next = reverseKGroup(forward , k);
        }
        return previous;
    }
};
    

// LEETCODE - STACKS

20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) 
    {
        stack<int> st;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(! st.empty())
                {
                    if(s[i] == ')' && st.top() == '(')
                    {
                        st.pop();
                    }
                    else if(s[i] == '}' && st.top() == '{')
                    {
                        st.pop();
                    }
                    else if(s[i] == ']' && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
        {
            return true;
        } 
        else
        {
            return false;
        }
    }
};

// LEETCODE - QUEUES
// LEETCODE - TREES

222. Count Complete Tree Nodes
class Solution {
public:
    int countNodes(TreeNode* root) 
    {
      if(root == NULL)
      {
        return 0;
      }
      else
      {
        return ( countNodes(root->left) + countNodes(root->right) + 1 );
      }
    }
};

104. Maximum Depth of Binary Tree
class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
          return 0;
        }
        else
        {
          int left = maxDepth(root->left);
          int right = maxDepth(root->right);
          int ans = max(left , right) + 1;
          return ans;
        }
    }
};

94. Binary Tree Inorder Traversal
class Solution {
public:
    void InOrderTraversal(TreeNode* root)
    {
      if(root != NULL)
      {
        InOrderTraversal(root->left);
        ans.push_back(root->val);
        InOrderTraversal(root->right);
      }
    }
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
      if(root == NULL)
      {
        return ans;
      }
      else
      {
        InOrderTraversal(root);
        return ans;
      }
    }
};

144. Binary Tree Preorder Traversal
class Solution {
public:
    void PreOrderTraversal(TreeNode* root)
    {
      if(root != NULL)
      {
        ans.push_back(root->val);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
      }
    }
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
      if(root == NULL)
      {
        return ans;
      }
      else
      {
        PreOrderTraversal(root);
        return ans;
      }
    }
};

145. Binary Tree Postorder Traversal
class Solution {
public:
    void PostOrderTraversal(TreeNode* root)
    {
      if(root != NULL)
      {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        ans.push_back(root->val);
      }
    }
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
        {
          return ans;
        }
        else
        {
          PostOrderTraversal(root);
          return ans;
        }
    }
};

110. Balanced Binary Tree
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
          return 0;
        }
        else
        {
          int left = height(root->left);
          int right = height(root->right);
          int ans = max(left , right) + 1;
          return ans;
        }
    }
    bool isBalanced(TreeNode* root) 
    {
      if(root == NULL)
      {
        return true;
      }  
      bool left = isBalanced(root->left);
      bool right = isBalanced(root->right);
      bool difference = abs(height(root->left) - height(root->right)) <= 1;
      if(left && right && difference)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
};

938. Range Sum of BST
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
      int ans = 0;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        TreeNode* temp = q.front();
        if(temp->val >= low && temp->val <= high)
        {
          ans = ans + temp->val;
        }
        q.pop();

        if(temp->left)
        {
          q.push(temp->left);
        }

        if(temp->right)
        {
          q.push(temp->right);
        }
      }
      return ans;
    }
};








// SINGLE LINKED LIST

class Node
{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

Node* head = NULL;

void Display(Node* &head)
{
    if(head == NULL)
    {
        cout << "No Linked List" << endl;
    }
    else
    {
        cout << "Linked List" << endl;
        Node* ptr = head;
        while(ptr != NULL)
        {
            cout << ptr->data << "  ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}

void InsertAtHead(Node* &head , int data)
{
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

void InsertAtTail(Node* &head , int data)
{
    Node* new_node = new Node(data);
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node* ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void InsertAtBefore(Node* &head , int data , int num)
{
    Node* ptr = head;
    Node* new_node = new Node(data);
    while(ptr->next->data != num)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void InsertAtAfter(Node* &head , int data , int num)
{
    Node* ptr = head;
    Node* new_node = new Node(data);
    while(ptr->data != num)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void DeleteAtHead(Node* &head)
{
    Node* ptr = head;
    head = head->next;
    free(ptr);
}

void DeleteAtTail(Node* &head)
{
    Node* ptr = head;
    Node* preptr = ptr;
    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}

void DeleteAtMiddle(Node* &head , int num)
{
    Node* ptr = head;
    Node* preptr = ptr;
    while(ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}

void Reverse(Node* &head)
{
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void Search(Node* &head , int num)
{
    Node* ptr = head;
    while(ptr->data != num)
    {
        ptr = ptr->next;
    }
    if(ptr->data == num)
    {
        cout << "Data " << num << " present" << endl;
    }
}

int FindLength(Node* &head)
{
    Node* ptr = head;
    int length = 0;
    while(ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    return length;
}

int FindMiddle(Node* &head)
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        Node* ptr = head;
        int length = FindLength(head);
        if(length % 2 == 0)
        {
            int count = 1;
            while(count != length/2)
            {
                count++;
                ptr = ptr->next;
            }
            return ptr->data;
        }
        else
        {
            int count = 0;
            while(count != length/2)
            {
                count++;
                ptr = ptr->next;
            }
            return ptr->data;
        }
    }
}

// STACKS USING ARRAYS

class Stack
{
    public:
        int *arr;
        int size;
        int top;
    
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    bool Empty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Full()
    {
        if(top == size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Push(int data)
    {
        if(top == size-1)
        {
            cout << "Stack is Full" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void Pop()
    {
        if(top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            top--;
        }
    }

    int Peek()
    {
        if(top == -1)
        {
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    int Size()
    {
        return top + 1;
    }

};

// STACKS USING LINKED LIST

class Node
{
    public:
        int data;
        Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    public:
        Node *top;

    Stack()
    {
        top = NULL;
    }

    bool Empty()
    {
        if(top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Push(int data)
    {
        Node *new_node = new Node(data);
        new_node->data = data;
        new_node->next = top;
        top = new_node;
    }

    void Pop()
    {
        if(top == NULL)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    int Peek()
    {
        if(top == NULL)
        {
            return -1;
        }
        else
        {
            return top->data;
        }
    }

};


