// SEI
case 0x78:
    this->setFlag('I', 1);
    break;
default:
    throw std::invalid_argument("Unknown opcode!");
    break;
