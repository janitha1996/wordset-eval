<p class="has-line-data" data-line-start="0" data-line-end="2">Name: - Janitha Mahanthe<br>
CS 525: - Systems Programming</p>
<p class="has-line-data" data-line-start="3" data-line-end="4">#wordset-evaluvator</p>
<p class="has-line-data" data-line-start="5" data-line-end="11">Workload will work for both queries and indentations.<br>
The workload can be handled by 1024 bytes per word to ensure workflow without overflow.<br>
Each workload file can be scaled 100 to 1000 words.<br>
This method will help with efficient workflow.<br>
Finally, this method will measure the hash map’s capability to manage insertions, lookups, and memory usage with load increments.<br>
with smaller workloads you can’t really get an idea about memory efficiency, But with extensive load you can get an idea about which method is more efficient.</p>
<p class="has-line-data" data-line-start="12" data-line-end="13">The evaluation compared the execution time for both C and Shell for workloads.</p>
<p class="has-line-data" data-line-start="14" data-line-end="20">Results are summarized below:<br>
program,mode,min,geomean,max<br>
c,I,2004,2606,9578<br>
c,Q,2027,2480,7432<br>
sh,I,2103,2496,7918<br>
sh,Q,1420,1693,5424</p>
<p class="has-line-data" data-line-start="21" data-line-end="23">Overall, both types will produce similar results in smaller workloads while c implementation will perform well under heavier workloads since proper memory management with c scripts.<br>
As the input size increases, both implementations show near-linear scaling in runtime, confirming that the hash map distributes keys evenly and avoids major slowdowns as data volume grows.</p>
<p class="has-line-data" data-line-start="24" data-line-end="30">Tread off with c vs shell<br>
C script will be very hard to write while it’s too hard to debug, while shell scripts are easy to write.<br>
But if we can write a C script with proper memory handling without flowing (or leaks), C script will be very efficient script.<br>
C script writing is very hard since you must do manual memory handling while, in shell you don’t have to do such memory handling.<br>
in conclusion C is better for performance while Shell can be used for simplicity<br>
While C offers maximum performance and precise control over memory, it’s harder to debug and maintain. Shell scripting, on the other hand, is simpler and more portable but sacrifices execution speed and memory control.</p>
