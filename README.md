# debuginfopass

An LLVM 3.8 pass that extracts debugging information (source line numbers and types) from LLVM IR, used to map analysis results back to student source code.

Built during the 2019 DREU summer research program at the University of Illinois Urbana-Champaign, where these passes powered an automated grading and hint-generation system for large CS courses, improving grading throughput by 10x.

Related passes: [pdg](https://github.com/aaguasvivas/pdg) (program dependence graph) and [cdg](https://github.com/aaguasvivas/cdg) (control dependence graph).
