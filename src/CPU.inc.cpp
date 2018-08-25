// SEI
case 0x78:
    this->setFlag('I', 1);
    this->cycle = 2;
    break;
// LDA #nn
case 0xA9:
    LDA(ADDRImmediate());
    this->cycle = 2;
    break;
// CLD
case 0xD8:
    this->setFlag('D', 0);
    this->cycle = 2;
    break;
default:
    throw std::invalid_argument("Unknown opcode!");
    break;
