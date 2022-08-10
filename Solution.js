
/**
 * @param {number[]} encoding
 */
var RLEIterator = function (encoding) {
    this.NOT_FOUND = -1;
    this.encoding = encoding;
    this.index = 0;
};

/** 
 * @param {number} nextNthElement
 * @return {number}
 */
RLEIterator.prototype.next = function (nextNthElement) {
    while (this.index < this.encoding.length - 1 && this.encoding[ this.index] - nextNthElement < 0) {
        nextNthElement -= this.encoding[this.index];
        this.index += 2;
    }
    if (this.index === this.encoding.length) {
        return this.NOT_FOUND;
    }

    this.encoding[ this.index] -= nextNthElement;
    return this.encoding[ this.index + 1];
};
