#!/usr/bin/env python3
import subprocess
import time
import statistics
import math

def run_program(program, workload):
    times = []

    with open(workload, 'r') as file:
        lines = file.readline()


    proc  = subprocess.Popen([program], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    for line in lines:
        start = time.perf_counter_ns()
        proc.stdin.write(line)
        proc.stdin.flush()
        end = time.perf_counter_ns()
        times.append(end - start)

    proc.stdin.close()
    proc.wait()
    return times

def geomean(data):
    return math.exp(sum(math.log(x) for x in data if x > 0) / len(data))


def evaluate():
    workloads = {
        "I": "test_inputs/insert.in",
        "Q": "test_inputs/query.in",
    }

    programs = {
        "c" : "./wordset.c",
        "sh": "./wordset.sh",
    }

    print(f"{'Program':<10} {'Workload':<15} {'Geomean Time (ns)':<20} {'Max Time (ns)':<15}")
    
    for prog_name, prog_path in programs.items():
        for mode, infile in programs.items():
            times =  run_program(prog_path, infile)
            print(f"{prog_name:<10} {mode:<15} {geomean(times):<20.2f} {max(times):<15}")


if __name__ == "__main__":
    evaluate()
