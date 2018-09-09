// BPL nnn
case 0x10: {
    CJMP('N', true);
    break;
}
// ROL nn
case 0x26: {
    ROL(ADDRZeropage());
    setCycle(5);
    break;
}
// BIT nnnn
case 0x2C: {
    BIT(ADDRAbsolute());
    setCycle(4);
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
    setCycle(3);
    break;
}
// SEI
case 0x78: {
    setFlag('I', 1);
    setCycle(2);
    break;
}
// TXS
case 0x9A: {
    TXS();
    setCycle(2);
    break;
}
// STY nn
case 0x84: {
    STY(ADDRZeropage());
    setCycle(3);
    break;
}
// STA nn
case 0x85: {
    STA(ADDRZeropage());
    setCycle(3);
    break;
}
// STA nnnn
case 0x8D: {
    STA(ADDRAbsolute());
    setCycle(4);
    break;
}
// LDX #nn
case 0xA2: {
    LDX(ADDRImmediate());
    setCycle(2);
    break;
}
// LDA #nn
case 0xA9: {
    LDA(ADDRImmediate());
    setCycle(2);
    break;
}
// LDA nnnn
case 0xAD: {
    LDA(ADDRAbsolute());
    setCycle(4);
    break;
}
// LDA nnnn, X
case 0xBD: {
    uint16_t address = this->PC;
    LDA(ADDRAbsoluteX());
    setCycle(4, address, this->PC);
    break;
}
// CMP #nn
case 0xC9: {
    CMP(ADDRImmediate());
    setCycle(2);
    break;
}
// CLD
case 0xD8: {
    setFlag('D', 0);
    setCycle(2);
    break;
}
default:
    printf("Opcode: 0x%02X; Address: 0x%04X;\n", this->memory->get(this->PC), this->PC);
    throw std::invalid_argument("Unknown opcode!");
    break;
