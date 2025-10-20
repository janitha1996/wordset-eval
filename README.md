Name: - Janitha Mahanthe
CS 525: - Systems Programming  

Workload will work for both queries and indentations.
The workload can be handled by 1024 bytes per word to ensure workflow without overflow. 
Each workload file can be scaled 100 to 1000 words.
This method will help with efficient workflow.
Finally, this method will measure the hash map’s capability to manage insertions, lookups, and memory usage with load increments.
with smaller workloads you can’t really get an idea about memory efficiency, But with extensive load you can get an idea about which method is more efficient.

The evaluation compared the execution time for both C and Shell for workloads.

Results are summarized below:
program,mode,min,geomean,max
c,I,2004,2606,9578
c,Q,2027,2480,7432
sh,I,2103,2496,7918
sh,Q,1420,1693,5424

Overall, both types will produce similar results in smaller workloads while c implementation will perform well under heavier workloads since proper memory management with c scripts. 
As the input size increases, both implementations show near-linear scaling in runtime, confirming that the hash map distributes keys evenly and avoids major slowdowns as data volume grows.

Tread off with c vs shell
   C script will be very hard to write while it’s too hard to debug, while shell scripts are easy to write.
   But if we can write a C script with proper memory handling without flowing (or leaks), C script will be very efficient script.
   C script writing is very hard since you must do manual memory handling while, in shell you don’t have to do such memory handling.
   in conclusion C is better for performance while Shell can be used for simplicity
While C offers maximum performance and precise control over memory, it’s harder to debug and maintain. Shell scripting, on the other hand, is simpler and more portable but sacrifices execution speed and memory control.

