// BPL nnn
case 0x10: {
    CJMP('N', true);
    break;    
}
// ROL nn
case 0x26: {
    ROL(ADDRZeropage());
    this->cycle = 5;
    break;
}
// BIT nnnn
case 0x2C: {
    BIT(ADDRAbsolute());
    this->cycle = 4;
    break;
}
// BMI nnn
case 0x30: {
    CJMP('N', false);
    break;
}
// JMP nnnn
case 0x4C: {
    JMP(ADDRAbsolute());
    this->cycle = 3;
    break;
}
// SEI
case 0x78: {
    this->setFlag('I', 1);
    this->cycle = 2;
    break;    
}
// TXS
case 0x9A: {
    TXS();
    this->cycle = 2;
    break;
}
// STA nn
case 0x85: {
    STA(ADDRZeropage());
    this->cycle = 3;
    break;
}
// STA nnnn
case 0x8D: {
    STA(ADDRAbsolute());
    this->cycle = 4;
    break;
}
// LDX #nn
case 0xA2: {
    LDX(ADDRImmediate());
    this->cycle = 2;
    break;    
}
// LDA #nn
case 0xA9: {
    LDA(ADDRImmediate());
    this->cycle = 2;
    break;    
}
// LDA nnnn
case 0xAD: {
    LDA(ADDRAbsolute());
    this->cycle = 4;
    break;
}
// LDA nnnn, X
case 0xBD: {
    uint16_t address = this->PC;
    LDA(ADDRAbsoluteX());
    this->cycle = 4 + this->isNextPage(address, this->PC);
    break;
}
// CLD
case 0xD8: {
    this->setFlag('D', 0);
    this->cycle = 2;
    break;
}
default:
    throw std::invalid_argument("Unknown opcode!");
    break;
