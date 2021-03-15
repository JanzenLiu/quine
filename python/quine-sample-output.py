import inspect
import sys

def replicate_itself(output_file):
    with open(output_file, 'w') as f:
        f.write('import inspect\n')
        f.write('import sys\n')
        f.write('\n')
        f.write(inspect.getsource(replicate_itself))
        f.write('\n')
        f.write('if __name__ == "__main__":\n')
        f.write('    output_file = sys.argv[1] if len(sys.argv) > 1 else "quine-output.py"\n')
        f.write('    replicate_itself(output_file)')

if __name__ == "__main__":
    output_file = sys.argv[1] if len(sys.argv) > 1 else "quine-output.py"
    replicate_itself(output_file)