
public class RLEIterator {

    private static final int NOT_FOUND = -1;
    int[] encoding;
    int index;

    public RLEIterator(int[] encoding) {
        this.encoding = encoding;
    }

    public int next(int nextNthElement) {
        while (index < encoding.length - 1 && encoding[index] - nextNthElement < 0) {
            nextNthElement -= encoding[index];
            index += 2;
        }
        if (index == encoding.length) {
            return NOT_FOUND;
        }

        encoding[index] -= nextNthElement;
        return encoding[index + 1];
    }
}
