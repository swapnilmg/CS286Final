# CS286Final

## Description
This project is out attempt to solve Zodiac 340 cipher. We first test our approach on Zodiac 408, for which we have the solution. Out hypothesis is based on assumption that we Zodiac 340 cipher has column transposition. To solve the column transposition, our hypothesis is that the HMM model trained with transposed cipher text will have less model probability when compared to model trained with non transposed cipher text. A matrix for the hypothesis will be digraph frequencies (not re-estimated during training).

## Testing for hypothesis
|  Experiment | Data | Transposed log probability | Non-Transposed log probability | Hypothesis Observation | Description |
| --- | --- | --- | --- | --- | --- |
|1|	Plain Text				|-1103.037| -1040.362|	Proved|	N = 26; M = 26; Iterations = 200;|
|2|	Plain Text				|-1099.859| -1040.362|	Proved|	N = 26; M = 26; Iterations = 200;|
|3|	Plain Text				|-1102.466| -1040.362|	Proved|	N = 26; M = 26; Iterations = 200;|
|4|	Simple Subsitution		|-1105.109| -1040.345|	Proved|	N = 26; M = 26; Iterations = 200;|
|5|	Homophonic Substitution	|-1438.761| -1415.551|	Proved|	N = 26; M = 54; Iterations = 200;|
|6|	Homophonic Substitution	|-1431.804| -1399.315|	Proved|	N = 26; M = 54; Iterations = 200; restarts = 10;|
