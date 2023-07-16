# CEPARCO-Cruz-Airon-DotMul
**Created by:** CRUZ, Airon John R.

**Google Collab link:** [Click here]([https://colab.research.google.com/drive/1a0_t27SoAJGNBdDdzNCDLzq6sP3mia2U#scrollTo=GjRLhEyQ0kDi](https://colab.research.google.com/drive/1OZSD0SEqFE6dZHn_Z7NKASLoSFogoicc?usp=sharing)

**Date:** July 15, 2023

An individual project for Parallel Computing class

## I. Comparison and Analysis of Execution Time

![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/3c6a888f-ba92-41f9-b0b3-03bce624e10a)

At a vector length ***(n) of 2^20***, the performance of different implementations was evaluated. The C implementation showed the slowest execution time, taking 3,133.33 microseconds (us) to complete. In contrast, both x86-64 implementations, the non-SIMD and SIMD, demonstrated relatively fast execution times of 933.33 us and 733.33 us, respectively. Specifically, the SIMD implementation exhibited a significant speed advantage over the C counterpart, being 4.3 times faster. Furthermore, it demonstrated a 1.27 times speed advantage over the x86-64 implementation. This notable difference in execution times among the first three versions can be attributed to the inherent advantage of SIMD's implementation, which leverages data-level parallelism to perform operations on multiple data elements simultaneously.

However, with the addition of the CUDA implementation, a remarkable improvement in performance was achieved, making it the fastest with an execution time of 427.72 us. Comparing it to the other versions, the CUDA implementation showcased a substantial speed advantage. It was found to be 7.32 times faster than the C version, 2.18 times faster than the non-SIMD version, and 1.71 times faster than the SIMD version. The reason behind this notable speed difference is that the CUDA implementation harnesses the power of parallel processing on a GPU, allowing for efficient execution of computations on large datasets. By distributing the workload across multiple cores, CUDA can achieve significant performance gains compared to the other implementations.

At a vector length ***(n) of 2^24***, the comparison between different implementations revealed interesting insights. The C implementation continued to exhibit the slowest execution time, taking a considerable 51,333.33 us to complete. In contrast, the x86-64 implementation showed improved performance with an execution time of 13,666.67 us, followed by the SIMD implementation with 10,966.67 us. However, the CUDA version once again emerged as the fastest, demonstrating its efficiency with an execution time of just 3,989.5 us. Looking at the performance variations from the perspective of SIMD, it was found that SIMD was now 4.7 times faster than its C counterpart and 1.25 times faster than x86-64. This showcased a significantly larger margin of efficiency for SIMD compared to the previous vector size. However, when comparing SIMD to the CUDA version, it became apparent that SIMD was 2.75 times slower than the fastest implementation, highlighting the superior performance of CUDA in this scenario.
Finally, at a vector length ***(n) of 229***, the CUDA implementation maintained its lead in terms of performance. The gap widens as CUDA’s execution is now  found to be 33.6 times faster than the C version, 9.1 times faster than the x86 non-SIMD version, and 7.2 times faster than the SIMD version. This significant difference further highlighted the performance advantage offered by the CUDA implementation over the other counterparts. Moreover, in addition to leading in terms of execution speed, CUDA consistently demonstrated a remarkable level of efficiency with minimal faults in both the GPU and CPU. On average, there were approximately 30 faults for each, except in the case of n = 2^20 where it had 149 CPU faults and 35 GPU faults. However, these faults did not degrade the overall performance of CUDA as the numbers just prove its reputation as a highly efficient and dependable solution for parallel processing tasks— at the expense of money and complexity in system setup. 

Overall, as the length of the vector increased, the CUDA implementation consistently outperformed the other implementations, showcasing its efficiency and ability to leverage the power of parallel processing on GPUs. While SIMD showed improvements compared to the C and x86-64 versions, it still fell short in terms of performance when compared to CUDA. Putting aside the specific version of CUDA employed, the consistent increasing trend in execution times observed across all vector sizes for the C, x86-64, and SIMD implementations indicates that SIMD remained the fastest among the three executions. Based on these observations, it can be concluded that SIMD offers a relatively efficient approach for executing dot product multiplications. These findings align with expectations, as SIMD leverages data-level parallelism to perform simultaneous operations on multiple data elements, resulting in improved performance. SIMD instructions are specifically designed to operate on multiple data elements simultaneously, enabling efficient processing of large datasets. On the other hand, the slower performance of the C implementation can be attributed to its classification as a "high-level" language, which provides a higher level of abstraction and programmer-friendly features. While these high-level features offer convenience and ease of use, they often come at the cost of performance optimization. Although both C and x86-64 performed the process sequentially, assembly programming, such as the x86-64 implementation, allows programmers to have fine-grained control over the hardware and executed instructions, resulting in lower execution times.


## II. Program Output Screenshots 
### ***INPUT:***
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/f0d53f68-7432-41dd-8976-bd7d5ef69416)


### A) C Implementation 
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/f25bf42f-ca35-4af9-95e5-e61bb59111cf)
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/89ae9e37-9e0b-4021-adbc-e537708f57bb)
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/9d9cc858-fb25-4af1-ae85-eaa9864965e0)


### B) x86-64 (Non-SIMD) Implementation
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/14fd9bc3-0771-481d-b381-58a1023e2e87)
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/d8808db2-3495-4ab0-9e5c-b506cbfb62ea)
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/40655212-a383-4eac-8a3c-da737f4714f7)


### C) SIMD-YMM register Implementation
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/c2c044cb-7fcc-448f-971c-42bfbaa5c948)
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/d9f98b2b-b654-410d-bfbc-678a93494f72)
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/cd4ba743-05c0-45bc-8a79-330cea45d8c8)

### D) CUDA Implementation
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/9210e02d-fb12-455c-92b2-24ac309b8d01)
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/2f4392b2-c89d-4e92-ba07-fc76cb6844af)
![image](https://github.com/thread120/CEPARCO-Cruz-Air-DotMul/assets/86954328/861bbf57-3f9b-43d9-b79c-5862ba266144)



